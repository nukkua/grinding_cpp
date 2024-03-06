#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
auto is_anagram(std::string s, std::string t) -> bool {
  bool band = false;
  std::sort(s.begin(), s.end());
  std::sort(t.begin(), t.end());
  if (s == t) {
    band = true;
  }

  return band;
}

auto is_anagram_unordered_map(std::string s, std::string t) -> bool {
  std::unordered_map<char, int> mp;

  for (const auto &x : s) {
    mp[x]++;
  }

  for (const auto &x : t) {
    mp[x]--;
  }
  for (const auto &x : mp) {
    if (x.second != 0) {
      return false;
    }
  }
  return true;
}

auto main() -> int {

  /* std::cout << is_anagram("coches", "chesco"); */
  std::cout << is_anagram_unordered_map("ab", "a");

  return 0;
}
