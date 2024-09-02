#include <algorithm>
#include <iostream>
#include <vector>

auto longest_consecutive(std::vector<int> &nums) -> int {
  int len = 0;
  int n = nums.size();
  std::sort(nums.begin(), nums.end());

  if (n == 0) {
    return len;
  }
  for (const auto &x : nums) {
    std::cout << x << "\n";
  }

  std::vector<int> sequence;
  int sequence_change = 0;
  sequence.push_back(nums[1] - nums[0]);

  return len;
}

auto main() -> int {
  std::vector<int> nums = {100, 4, 200, 1, 3, 2};
  std::cout << longest_consecutive(nums);

  return 0;
}
