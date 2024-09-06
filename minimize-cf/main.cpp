#include <iostream>

#pragma GCC optimize("03")

#define endl '\n'

#define fastio()                                                               \
  std::ios_base::sync_with_stdio(0);                                           \
  std::cin.tie(0);                                                             \
  std::cout.tie(0);

signed main() {
  fastio();

  int t;
  std::cin >> t;

  while (t--) {
    int a, b;
    std::cin >> a >> b;

    std::cout << b - a << endl;
  }

  return 0;
}
