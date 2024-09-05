#include <iostream>
#include <vector>

#pragma GCC optimize("03")

#define fastio()                                                               \
  std::ios_base::sync_with_stdio(0);                                           \
  std::cin.tie(0);                                                             \
  std::cout.tie(0)

using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main() {
  fastio();

  int t;
  std::cin >> t;
  while (t--) [[likely]] {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    ll sum = 0, P = 0;
    for (auto &x : a) [[likely]] {
      std::cin >> x;
      sum += x;
    }
    for (int i = 0; i < n; ++i) [[likely]] {
      sum -= a[i];
      P += a[i] * sum;
    }
    ll Q = (n * (n - 1) / 2);

    std::cout << P << "\n";
    std::cout << Q << "\n";
  }
  return 0;
}
