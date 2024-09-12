#include <iostream>
#include <queue>
#include <vector>

#pragma GCC optimize("03")

#define endl '\n'

#define INF 0x3f3f3f3f

#define fastio()                                                               \
  std::ios_base::sync_with_stdio(0);                                           \
  std::cin.tie(0);                                                             \
  std::cout.tie(0);

auto inline bfs(std::vector<std::vector<int>> &list,
                int init) -> std::vector<int> {
  int n = list.size();
  std::vector<int> d(n, INF);

  std::queue<int> q;
  q.push(init);
  d[init] = 0;

  while (!q.empty()) {
    int x = q.front();
    q.pop();

    for (auto &y : list[x]) {
      if (d[y] == INF) {
        d[y] = d[x] + 1;
        q.push(y);
      }
    }
  }

  return d;
}

signed main() {
  fastio();

  int queries;
  std::cin >> queries;
  while (queries--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> list(n);
    for (int i = 0; i < m; ++i) {
      int x;
      int y;
      std::cin >> x >> y;
      --x;
      --y;
      list[x].push_back(y);
      list[y].push_back(x);
    }

    std::vector<int> im;
    auto distances = bfs(list, 0);
    std::vector<int> pa;
    for (int i = 0; i < n; ++i) {
      if (distances[i] & 1) {
        im.push_back(i);
      } else {
        pa.push_back(i);
      }
    }
    if (im.size() < pa.size()) {
      std::cout << im.size() << endl;
      for (const auto &z : im) {
        std::cout << z + 1 << " ";
      }
    } else {
      std::cout << pa.size() << endl;
      for (const auto &z : pa) {
        std::cout << z + 1 << " ";
      }
    }
    std::cout << endl;
  }

  return 0;
}
