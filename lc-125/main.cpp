#include <cctype>
#include <iostream>
#include <string>

auto is_palyndrome(std::string s) -> bool {
  int n = s.size();
  std::string verifier = "";
  std::string resol;
  /* std::isalpha(CharT, const locale &) */
  /* std::isdigit(CharT, const locale &) */

  for (int i = 0; i < n; ++i) {
    if (std::isalnum(s[i])) {
      resol += tolower(s[i]);
    }
  }
  for (int i = resol.size() - 1; i >= 0; --i) {
    verifier += resol[i];
  }
  if (resol == verifier) {
    return true;
  }

  return false;
}

auto main() -> int {
  std::cout << is_palyndrome("0P");
  return 0;
}
