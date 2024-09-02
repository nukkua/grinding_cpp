#include <iostream>
int main() {

  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  int n;

  std::cin >> n;

  while (n--) {
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
