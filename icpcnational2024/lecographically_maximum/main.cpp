#include <iostream>
#include <vector>

auto main() -> int {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

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
