#include <iostream>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr){};
  ListNode(int x) : val(x), next(nullptr){};

  ListNode(int x, ListNode *nextPtr) : val(x), next(nextPtr){};
};
auto add_two_numbers(ListNode *l1, ListNode *l2) -> ListNode * {
  ListNode *reusable = new ListNode();
  ListNode *res = reusable;
  int total = 0, curry = 0;

  while (l1 || l2 || curry) {

    total = curry;

    if (l1) {
      total += l1->val;
      l1 = l1->next;
    }
    if (l2) {
      total += l2->val;
      l2 = l2->next;
    }

    int num = total % 10;
    curry = total / 10;

    reusable->next = new ListNode(num);

    reusable = reusable->next;
  }

  return res->next;
}

auto main() -> int {

  std::vector<ListNode *> lk1;
  std::vector<ListNode *> lk2;
  std::vector<int> lk1_values = {2, 4, 3};
  std::vector<int> lk2_values = {5, 6, 4};

  lk1.push_back(new ListNode(lk1_values[0]));
  lk2.push_back(new ListNode(lk2_values[0]));

  for (int i = 1; i < lk1_values.size(); ++i) {
    lk1.push_back(new ListNode(lk1_values[i], lk1[i - 1]));
  }
  for (int i = 1; i < lk2_values.size(); ++i) {
    lk2.push_back(new ListNode(lk2_values[i], lk2[i - 1]));
  }

  auto result =
      add_two_numbers(lk1[lk1.size() - 1], lk2[lk2_values.size() - 1]);
  ListNode *temp = result;
  while (temp) {
    std::cout << temp->val << '\n';
    temp = temp->next;
  }

  return 0;
}
