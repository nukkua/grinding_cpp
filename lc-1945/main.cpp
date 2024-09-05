#include <iostream>
#include <string>

#pragma GCC optimize("03")

#define fastio()                                                               \
  std::ios_base::sync_with_stdio(0);                                           \
  std::cin.tie(0);                                                             \
  std::cout.tie(0);

#define endl '\n'

auto inline getLucky2(std::string s, int k) noexcept -> int {
  std::string number = "";

  for (const char &x : s) {
    number += std::to_string(x - 'a' + 1);
  }
  while (k--) {
    int temp = 0;
    for (const char &x : number) {
      temp += x - '0';
    }

    number = std::to_string(temp);
  }

  return std::stoi(number);
}

auto getDigit(int a) -> int {
  if (a / 10 == 0) {
    return a;
  }

  int acum = 0;
  while (a > 0) {
    acum += a % 10;
    a /= 10;
  }

  return acum;
}

auto getLucky(std::string s, int k) -> int {
  int result = 0;

  for (const char &x : s) {
    result += getDigit(int(x - 'a') + 1);
  }
  k--;

  while (k > 0) {
    result = getDigit(result);
    k--;
  }

  return result;
}
signed main() {
  fastio();

  /* auto start = std::chrono::high_resolution_clock::now(); */

  /* std::cout << getLucky("zbax", 2) << endl; */
  /* std::cout << getDigit(11) << endl; */

  std::cout << getLucky2("aaaa", 1) << endl;

  /* auto end = std::chrono::high_resolution_clock::now(); */
  /* std::chrono::duration<double> elapsed = end - start; */

  /* std::cout << elapsed.count() << endl; */

  return 0;
}
