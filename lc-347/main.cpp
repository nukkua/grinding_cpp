#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

auto top_k_frequent(std::vector<int> &nums, int k) -> std::vector<int> {
  std::unordered_map<int, int> mp;
  std::vector<int> sol;
  for (const auto &x : nums) {
    mp[x]++;
  }
  std::vector<std::pair<int, int>> elems(mp.begin(), mp.end());
  std::sort(elems.begin(), elems.end(),
            [](std::pair<int, int> &a, std::pair<int, int> &b) -> bool {
              return a.second > b.second;
            });
  for (int i = 0; i < k; i++) {
    sol.push_back(elems[i].first);
  }

  return sol;
}

auto main() -> int {
  std::vector<int> nums = {20, 10, 10, 3, 3, 4, 2, 2, 2};
  auto solution = top_k_frequent(nums, 3);

  for (const auto &x : solution) {
    std::cout << x << " ";
  }

  return 0;
}
