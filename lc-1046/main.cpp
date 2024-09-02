#include <bits/stdc++.h>

auto last_stone_weight(std::vector<int> &stones) -> int {
  int sol = 0;
  std::priority_queue<int> pq(stones.begin(), stones.end());
  std::priority_queue<int, std::vector<int>, std::greater<int>> pq2;
  while (pq.size() > 1) {
    int max1 = pq.top();
    pq.pop();
    int max2 = pq.top();
    pq.pop();
    pq.push(max1 - max2);
  }

  return pq.empty() ? 0 : pq.top();
}

auto main() -> int {

  std::vector<int> v = {2, 8, 3, 7, 9, 10};
  std::cout << last_stone_weight(v);
  return 0;
}
