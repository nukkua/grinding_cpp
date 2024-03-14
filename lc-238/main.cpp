#include <iostream>
#include <vector>

std::vector<int> productExceptSelf(std::vector<int> &nums) {
  int n = nums.size();
  std::vector<int> sol(n);
  sol[0] = 1;
  for (int i = 1; i < n; ++i) {
    sol[i] = sol[i - 1] * nums[i - 1];
  }

  int right_verifier = 1;

  for (int i = n - 1; i >= 0; --i) {
    sol[i] = sol[i] * right_verifier;
    right_verifier *= nums[i];
  }

  return sol;
}

auto productExceptSelf_brute_force(std::vector<int> &nums) -> std::vector<int> {
  int n = nums.size();
  std::vector<int> sol(n);
  int multiplier = 1;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j)
        continue;
      multiplier *= nums[i];
    }
    sol[i] = multiplier;
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
