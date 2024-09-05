#include <iostream>

#pragma GCC optimize("03")

#define fastio()                                                               \
  std::ios_base::sync_with_stdio(0);                                           \
  std::cin.tie(0);                                                             \
  std::cout.tie(0);

signed main() {
  fastio();

  int n;

  std::cin >> n;

  while (n--) [[likely]] {
    int a, b;
    std::cin >> a >> b;
    if ((a & 1)) [[likely]] {
      std::cout << "NO" << '\n';
    } else {
      if ((b & 1) == 0) {
        std::cout << "YES" << '\n';
      } else {
        if (a == 0) [[unlikely]]
          std::cout << "NO" << '\n';
        else
          std::cout << "YES" << '\n';
      }
    }
  }

  return 0;
}
