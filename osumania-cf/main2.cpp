#include <iostream>
#include <vector>

#pragma GCC optimize("03")
#pragma GCC optimize("Ofast")


#define fastio()                                                               \
  std::ios_base::sync_with_stdio(0);                                           \
  std::ios::sync_with_stdio(0);                                                \
  std::cin.tie(0);                                                             \
  std::cout.tie(0);

#define endl '\n'

signed main() {
  fastio();

  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<std::string> notes(n);
    notes.reserve(n);

    for (int i = 0; i < n; ++i)
      std::cin >> notes[i];

    for (int i = n - 1; ~i; --i) {
      for (int j = 0; j < 4; ++j) {
        if (notes[i][j] == '#') {
          std::cout << j + 1 << " ";
        }
      }
    }
    std::cout << endl;
  }

  return 0;
}
