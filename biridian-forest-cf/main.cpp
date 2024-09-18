#include <iostream>
#include <queue>
#include <vector>

#pragma GCC optimize("03")

#define endl '\n'

#define INF 0x7fffffff

#define fastio()                                                               \
  std::ios_base::sync_with_stdio(0);                                           \
  std::cin.tie(0);                                                             \
  std::cout.tie(0);

struct p {
  int x;
  int y;
};

signed main() {
  fastio();

  int r, c;
  std::cin >> r >> c;

  p start, end;

  std::vector<std::vector<char>> forest(r, std::vector<char>(c));
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      std::cin >> forest[i][j];
      if (forest[i][j] == 'S') {
        start = p{i, j};

      } else if (forest[i][j] == 'E') {
        end = p{i, j};
      }
    }
  }

  int dx[] = {-1, +1, 0, 0};
  int dy[] = {0, 0, +1, -1};

  std::queue<p> q;
  std::vector<std::vector<int>> d(r, std::vector<int>(c, INF));
  q.push(end);
  d[end.x][end.y] = 0;

  while (!q.empty()) {
    p curr = q.front();
    q.pop();

    for (int i = 0; i < 4; ++i) {
      int nx = curr.x + dx[i];
      int ny = curr.y + dy[i];

      if (nx < 0 || ny < 0 || nx >= r || ny >= c || d[nx][ny] != INF ||
          forest[nx][ny] == 'T')
        continue;

      d[nx][ny] = d[curr.x][curr.y] + 1;
      q.push(p{nx, ny});
    }
  }

  int num_enemies = 0;
  int dist_start = d[start.x][start.y];

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (d[i][j] <= dist_start && forest[i][j] >= '0' && forest[i][j] <= '9') {
        num_enemies += (forest[i][j] - '0');
      }
    }
  }
  std::cout << num_enemies << endl;

  return 0;
}
