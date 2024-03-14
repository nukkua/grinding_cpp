#include <iostream>
#include <vector>

std::vector<int> productExceptSelf(std::vector<int> &nums) {
  std::vector<int> sol(nums.size());

  int n = nums.size();
  int multiplier_1 = 1;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i != j) {
        multiplier_1 *= nums[j];
      }
    }
    sol[i] = multiplier_1;
    multiplier_1 = 1;
  }

  return sol;
}

auto main() -> int {

  std::vector<int> nums = {4, 1, 2, 5};

  auto ala = productExceptSelf(nums);

  for (const auto &x : ala) {
    std::cout << x << " ";
  }

  return 0;
}
