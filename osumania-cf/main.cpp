#include <iostream>
#include <vector>

#pragma GCC optimize("03")

#define fastio()                                                               \
  std::ios_base::sync_with_stdio(0);                                           \
  std::cin.tie(0);                                                             \
  std::cout.tie(0);

#define endl '\n'

signed main() {
  int t;
  fastio();

  std::cin >> t;

  while (t--) {
    int n = 0;
    std::cin >> n;
    std::vector<int> lec;
    while (n--) {
      std::string notes = "";

      lec.reserve(n);

      std::cin >> notes;

      for (int i = 0; i < notes.size(); ++i) {
        if (notes[i] == '#') {
          lec.push_back(i + 1);
        }
      }
    }

    for (int i = lec.size() - 1; ~i; --i) {
      std::cout << lec[i] << " ";
    }
    std::cout << endl;
  }

  return 0;
}
