#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

auto constains_duplicate(std::vector<int> &nums) noexcept -> bool {
  bool it_contains = true;
  std::unordered_set<int> nums2;
  for (int i = 0; i < nums.size(); ++i) {
    nums2.insert(nums[i]);
  }

  if (nums.size() == nums2.size()) {
    it_contains = false;
  }

  return it_contains;
}

auto contains_duplicate_one_line(std::vector<int> &nums) noexcept -> bool {
  return nums.size() > std::unordered_set<int>(nums.begin(), nums.end()).size();
}

bool contains_duplicate_unordered_map(std::vector<int> &nums) {
  std::unordered_map<int, int> mp;
  for (const auto &x : nums) {
    mp[x]++;
  }
  for (const auto &i : mp) {
    if (i.second >= 2)
      return true;
  }
  return false;
}

auto main() -> int {
  int n;
  std::cin >> n;
  std::vector<int> nums(n);

  for (int i = 0; i < n; ++i) {
    std::cin >> nums[i];
  }
  std::cout << "Results: ";
  std::cout << "\n";
  std::cout << contains_duplicate_one_line(nums);
  std::cout << "\n";
  std::cout << constains_duplicate(nums);
  std::cout << "\n";
  std::cout << contains_duplicate_unordered_map(nums);
  std::cout << "\n";

  return 0;
}
