#include <iostream>
#include <vector>

#pragma GCC optimize("03");

#define fastio()                                                               \
  std::ios_base::sync_with_stdio(0);                                           \
  std::cin.tie(0);                                                             \
  std::cout.tie(0);

auto main() -> int {
  fastio();

  int n;
  int orsito;
  std::cin >> n;
  std::vector<int> integers(n);

  for (int i = 0; i < n; i++) {
    std::cin >> integers[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      orsito = integers[i];
      integers[i] |= integers[j];
      integers[j] &= orsito;
    }
    std::cout << integers[i] << " ";
  }

  return 0;
}
