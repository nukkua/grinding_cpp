#include <deque>
#include <iostream>
#include <tuple>
#include <vector>

#pragma GCC optimize("03")

#define fastio()                                                               \
  std::ios_base::sync_with_stdio(0);                                           \
  std::cin.tie(0);                                                             \
  std::cout.tie(0);

#define pii std::pair<int, int>
#define tiiii std::tuple<int, int, int, int>
#define endl '\n'

signed main() {
  fastio();

  int n, m, r, c, x, y;
  std::cin >> n >> m >> r >> c >> x >>
      y; // x is max left moves, y is max right moves

  std::vector<std::vector<char>> labyrinth(n, std::vector<char>(m));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      std::cin >> labyrinth[i][j];

  std::deque<std::tuple<int, int, int, int>>
      dq; // {row, col, left_used, right_used}
  std::vector<std::vector<int>> visited(n, std::vector<int>(m, 0));
  dq.push_front({r - 1, c - 1, 0, 0});
  visited[r - 1][c - 1] = 1;

  int reachable = 0;
  while (!dq.empty()) {
    auto [i, j, left_used, right_used] = dq.front();
    dq.pop_front();
    ++reachable;

    std::vector<pii> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (auto [di, dj] : directions) {
      int ni = i + di, nj = j + dj;
      if (ni >= 0 && ni < n && nj >= 0 && nj < m && labyrinth[ni][nj] == '.') {
        if (dj == -1 && left_used < x && !visited[ni][nj]) { // Move left
          dq.push_back({ni, nj, left_used + 1, right_used});
          visited[ni][nj] = 1;
        } else if (dj == 1 && right_used < y &&
                   !visited[ni][nj]) { // Move right
          dq.push_back({ni, nj, left_used, right_used + 1});
          visited[ni][nj] = 1;
        } else if (di != 0 && !visited[ni][nj]) { // Move up or down
          dq.push_front({ni, nj, left_used, right_used});
          visited[ni][nj] = 1;
        }
      }
    }
  }

  std::cout << reachable << endl;
  return 0;
}
