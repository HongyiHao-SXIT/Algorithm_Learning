#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int getLength(ListNode* head) {
        int length = 0;
        while (head) {
            ++length;
            head = head->next;
        }
        return length;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        int length = getLength(head);
        ListNode* cur = dummy;
        
        for (int i = 1; i < length - n + 1; ++i) {
            cur = cur->next;
        }
        
        ListNode* toDelete = cur->next;
        cur->next = cur->next->next;
        delete toDelete;
        
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};

void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    std::cout << "Original list: ";
    printList(head);

    head = solution.removeNthFromEnd(head, 2);
    std::cout << "After removing 2nd from end: ";
    printList(head);

    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}