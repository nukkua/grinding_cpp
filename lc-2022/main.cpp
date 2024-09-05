#include <iostream>
#include <vector>

#define fastio()                                                               \
  std::ios_base::sync_with_stdio(0);                                           \
  std::cin.tie(0);                                                             \
  std::cout.tie(0);

#define endl '\n'

#pragma GCC optimize("03")

auto construct2DArray(std::vector<int> &original, int m,
                      int n) -> std::vector<std::vector<int>> {
}

signed main() {
  fastio();

  int m = 1;
  int n = 3;

  std::vector<int> v1 = {1, 2, 3};
  auto result = construct2DArray(v1, m, n);
  if (n > 1) {
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        std::cout << result[i][j] << " ";
      }
      std::cout << endl;
    }
  }

  return 0;
}
