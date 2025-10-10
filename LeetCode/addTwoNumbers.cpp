#include <iostream>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* List1, ListNode* List2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    int carry = 0;

    while (List1 || List2 || carry) {
      int n1 = List1 ? List1->val : 0;
      int n2 = List2 ? List2->val : 0;
      int sum = n1 + n2 + carry;

      tail->next = new ListNode(sum % 10);
      tail = tail->next;

      carry = sum / 10;
      List1 = List1 ? List1->next : nullptr;
      List2 = List2 ? List2->next : nullptr;
    }

    return dummy.next;
  }
};
