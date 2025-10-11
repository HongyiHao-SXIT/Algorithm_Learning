#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *deleteMinAndReplace(ListNode *head) {
  if (!head || !head->next) {
    if (head)
      delete head;
    return nullptr;
  }

  ListNode *minNode = head;
  ListNode *cur = head;
  ListNode *prev = nullptr;
  ListNode *prevMin = nullptr;

  while (cur) {
    if (cur->val < minNode->val) {
      minNode = cur;
      prevMin = prev;
    }
    prev = cur;
    cur = cur->next;
  }

  ListNode *lastNode = prev;

  minNode->val = lastNode->val;

  if (head == lastNode) {
    delete lastNode;
    return nullptr;
  } else {
    ListNode *p = head;
    while (p->next != lastNode) {
      p = p->next;
    }
    p->next = nullptr;
    delete lastNode;
  }

  return head;
}

void printList(ListNode *head) {
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

int main() {
  ListNode *head = new ListNode(5);
  head->next = new ListNode(2);
  head->next->next = new ListNode(7);
  head->next->next->next = new ListNode(3);

  cout << "Original list: ";
  printList(head);

  head = deleteMinAndReplace(head);

  cout << "After deleteMinAndReplace: ";
  printList(head);

  return 0;
}
