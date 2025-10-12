#include <iostream>

const int MAX_NODES = 100010;

struct Node {
    int value;
    int next;
};

Node nodes[MAX_NODES];

int headIndex = -1;
int nodeCount = 0;

void initialize() {
    headIndex = -1;
    nodeCount = 0;
}

void insertAtHead(int value) {
    nodes[nodeCount].value = value;
    nodes[nodeCount].next = headIndex;
    headIndex = nodeCount;
    nodeCount++;
}

void deleteAfterK(int k) {
    if (k == 0) {
        headIndex = nodes[headIndex].next;
    } else {
        int prevIndex = k - 1;
        nodes[prevIndex].next = nodes[nodes[prevIndex].next].next;
    }
}

void insertAfterK(int k, int value) {
    int prevIndex = k - 1;
    nodes[nodeCount].value = value;
    nodes[nodeCount].next = nodes[prevIndex].next;
    nodes[prevIndex].next = nodeCount;
    nodeCount++;
}

int main() {
    initialize();

    int operationCount;
    std::cin >> operationCount;

    while (operationCount--) {
        char operation;
        std::cin >> operation;

        if (operation == 'H') {
            int value;
            std::cin >> value;
            insertAtHead(value);
        } else if (operation == 'D') {
            int k;
            std::cin >> k;
            deleteAfterK(k);
        } else if (operation == 'I') {
            int k, value;
            std::cin >> k >> value;
            insertAfterK(k, value);
        }
    }

    for (int i = headIndex; i != -1; i = nodes[i].next) {
        std::cout << nodes[i].value << " ";
    }
    std::cout << std::endl;

    return 0;
}
