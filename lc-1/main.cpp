#include <iostream>
#include <unordered_map>
#include <vector>

auto two_sum_brute_force(std::vector<int> &nums, int target)
    -> std::vector<int> {
  int n = nums.size();
  std::vector<int> sol = {0, 0};

  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (nums[i] + nums[j] == target) {
        sol[0] = i;
        sol[1] = j;
      }
    }
  }
  return sol;
}

auto two_sum_hash_map(std::vector<int> &nums, int target) -> std::vector<int> {
  int n = nums.size();
  std::unordered_map<int, int> mp;

  for (int i = 0; i < n; ++i) {
    int complement = target - nums[i];

    if (mp.count(complement)) {
      return {mp[complement], i};
    }

    mp[nums[i]] = i;
  }
  return {};
}

auto main() -> int {
  std::vector<int> al = {10, 4, 23, 2, 6};
  int target = 8;

  /* auto solution = two_sum_brute_force(al, target); */
  auto solution = two_sum_hash_map(al, target);

  for (const auto &x : solution) {
    std::cout << x << " ";
  }

  return 0;
}
