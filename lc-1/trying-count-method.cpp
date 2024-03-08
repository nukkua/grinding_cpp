#include <iostream>
#include <unordered_map>
#include <vector>

auto main() -> int {
  std::unordered_map<int, int> mp;

  std::vector<int> v = {10, 2, 4, 5, 6};

  int cont = 0;

  for (const auto &x : v) {
    mp[x] = cont;
    cont++;
  }

  for (const auto &x : mp) {
    std::cout << x.first << " " << x.second << " \n";
  }

  std::cout << mp.count(10);

  return 0;
}
