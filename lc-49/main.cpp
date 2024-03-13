#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

auto group_anagram(std::vector<std::string> &strs)
    -> std::vector<std::vector<std::string>> {
  std::unordered_map<std::string, std::vector<std::string>> mp;
  std::vector<std::vector<std::string>> sol;
  for (std::string &x : strs) {
    std::string aux = x;
    std::sort(x.begin(), x.end());
    mp[x].push_back(aux);
  }

  for (const auto &x : mp) {
    sol.push_back(x.second);
  }

  return sol;
}

auto main() -> int {

  std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  auto sol = group_anagram(strs);

  return 0;
}
