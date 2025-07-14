#ifndef NODE_H
#define NODE_H

#include "Student.h"

class Node {
public:
    Student data;
    Node* next;

    Node(const Student& data);
};

#endif