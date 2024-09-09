#include <chrono>
#include <cmath>
#include <iomanip>
#include <iostream>

#pragma GCC optimize("03")

#define endl '\n'

#define fastio()                                                               \
  std::ios_base::sync_with_stdio(0);                                           \
  std::cin.tie(0);                                                             \
  std::cout.tie(0);

template <typename T> inline void read(T &x) {
  x = 0;
  bool f = false;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-')
      f = true;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x * 10) + (c ^ 48);
    c = getchar();
  }
  if (f)
    x = -x;
}
template <typename T, typename... Args>
inline void read(T &tmp, Args &...tmps) {
  read(tmp);
  read(tmps...);
}

auto inline benchmark = [](auto fun, auto rem) {
  const auto start = std::chrono::high_resolution_clock::now();
  fun();

  const std::chrono::duration<double> diff =
      std::chrono::high_resolution_clock::now() - start;
  std::cout << "Time: " << std::fixed << std::setprecision(6) << diff.count()
            << " sec " << rem << endl;
};

signed main() { return 0; }
