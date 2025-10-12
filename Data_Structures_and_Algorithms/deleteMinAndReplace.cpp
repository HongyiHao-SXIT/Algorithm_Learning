#include <iostream>

struct ListNode {
    int value;
    ListNode* next;
    ListNode(int val) : value(val), next(nullptr) {}
};

ListNode* deleteMinAndReplace(ListNode* head) {
    if (!head || !head->next) {
        delete head;
        return nullptr;
    }

    ListNode* minNode = head;
    ListNode* current = head;
    ListNode* previous = nullptr;
    ListNode* previousMin = nullptr;

    while (current) {
        if (current->value < minNode->value) {
            minNode = current;
            previousMin = previous;
        }
        previous = current;
        current = current->next;
    }

    ListNode* lastNode = previous;

    minNode->value = lastNode->value;

    if (head == lastNode) {
        delete lastNode;
        return nullptr;
    } else {
        ListNode* temp = head;
        while (temp->next != lastNode) {
            temp = temp->next;
        }
        temp->next = nullptr;
        delete lastNode;
    }

    return head;
}

void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp) {
        std::cout << temp->value << " ";
        temp = temp->next;
    }
    std::cout << "\n";
}

int main() {
    ListNode* head = new ListNode(5);
    head->next = new ListNode(2);
    head->next->next = new ListNode(7);
    head->next->next->next = new ListNode(3);

    std::cout << "Original list: ";
    printList(head);

    head = deleteMinAndReplace(head);

    std::cout << "After deleteMinAndReplace: ";
    printList(head);

    return 0;
}
