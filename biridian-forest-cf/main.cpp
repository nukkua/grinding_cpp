#include <iostream>
#include <queue>
#include <vector>

#pragma GCC optimize("03")

#define endl '\n'
#define INF 0x3f3f3f3f

#define pii std::pair<int, int>
#define mp std::make_pair

#define fastio()                                                               \
  std::ios_base::sync_with_stdio(0);                                           \
  std::cin.tie(0);                                                             \
  std::cout.tie(0);

struct Point {
  int x;
  int y;
};

int main() {
  fastio();
  int r, c;
  std::cin >> r >> c;

  std::vector<std::vector<char>> forest(r, std::vector<char>(c));
  Point end_point;
  Point start_point;

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      std::cin >> forest[i][j];
      if (forest[i][j] == 'E') {
        end_point = Point{i, j}; // End point
      } else if (forest[i][j] == 'S') {
        start_point = Point{i, j}; // Start point
      }
    }
  }

  std::vector<std::vector<int>> d(r, std::vector<int>(c, INF));

  int dx[] = {-1, +1, 0, 0};
  int dy[] = {0, 0, +1, -1};

  std::queue<Point> q;

  q.push(end_point);
  d[end_point.x][end_point.y] = 0;

  while (!q.empty()) {
    Point curr = q.front();
    q.pop();

    for (int i = 0; i < 4; ++i) {
      int nx = curr.x + dx[i];
      int ny = curr.y + dy[i];

      if (nx < 0 || ny < 0 || nx >= r || ny >= c || forest[nx][ny] == 'T' ||
          d[nx][ny] != INF)
        continue;

      d[nx][ny] = d[curr.x][curr.y] + 1;
      q.push(Point{nx, ny});
    }
  }

  int num_enemies = 0;

  int dist_start = d[start_point.x][start_point.y];

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
