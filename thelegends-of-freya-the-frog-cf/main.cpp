#include <iostream>

#pragma GCC optimize("03")

#define fastio()                                                               \
  std::ios_base::sync_with_stdio(0);                                           \
  std::cin.tie(0);                                                             \
  std::cout.tie(0);

#define int long long
#define endl "\n"
#define mod 1000000007

signed main() {
  fastio();
  int t;
  std::cin >> t;
  while (t--) {
    int x, y, k;
    std::cin >> x >> y >> k;
    int nx = (x + k - 1) / k; // ceiling
    int ny = (y + k - 1) / k; // ceiling
    int ans = std::max(2 * nx - 1, 2 * ny);
    std::cout << ans << endl;
  }
}
