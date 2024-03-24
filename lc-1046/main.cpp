#include <iostream>
#include <queue>
#include <vector>

auto last_stone_weight(std::vector<int> &stones) -> int {
  int sol = 0;
  std::priority_queue<int> pq(stones.begin(), stones.end());

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

  std::vector<int> v = {2, 7, 4, 1, 8, 1};
  std::cout << last_stone_weight(v);
  return 0;
}
