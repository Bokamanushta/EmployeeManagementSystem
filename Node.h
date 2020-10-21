#ifndef NODE_H
#define NODE_H
#include "Employee.h"
class Node
{
public:
    Employee employee;
    Node *next;
    Node(Employee);
};

#endif // NODE_H
