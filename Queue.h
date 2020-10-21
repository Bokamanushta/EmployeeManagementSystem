#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"
#include "Employee.h"

class Queue{
    public:
        Node *bckptr, *fptr;
        void createQueue();
        void destroyQueue();
        bool isEmpty();
        void enqueue(Employee);
        void dequeue();
        Employee findEmployeeByName(string);
        Employee* findEmployeeByRef(string);
        int getTotalEmployee();
        string getAllEMployee();
};
#endif // QUEUE_H
