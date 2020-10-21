#include "Queue.h"
#include "string.h"

void Queue ::createQueue(){bckptr=fptr=NULL;}
void Queue ::destroyQueue(){
    Node *tmp = fptr;
    while(tmp){
        fptr = tmp->next;
        delete tmp;
        tmp = fptr;
    }
}

bool Queue ::isEmpty(){return (fptr == NULL && bckptr == NULL);}

void Queue ::enqueue(Employee emp){
    Node * nw = new Node(emp);
    if(isEmpty()) fptr = bckptr = nw;
    else{
        bckptr->next = nw;
        bckptr = nw;
    }
}

void Queue ::dequeue(){
    Node * tmp = fptr;
    fptr = fptr->next;
    tmp->next = NULL;
    delete tmp;
    if(!fptr) bckptr = NULL;
}

Employee Queue ::findEmployeeByName(string n){
    Node * tmp = fptr;
    while(tmp && (tmp->employee.getName().compare(n) != 0)){
         tmp = tmp->next;
    }
    if(tmp) return tmp->employee;
    return *new Employee ("",0.0,"",false,0.0,*new LeaveApplication("","",""),0);
}

Employee* Queue ::findEmployeeByRef(string n){
    Node * tmp = fptr;
    while(tmp && (tmp->employee.getName().compare(n) != 0)){
         tmp = tmp->next;
    }
    if(tmp) return &tmp->employee;
    return new Employee ("",0.0,"",false,0.0,*new LeaveApplication("","",""),0);
}

int Queue ::getTotalEmployee(){
    Node * tmp = fptr;
    int count =0;
    while(tmp){
        count++;
        tmp = tmp->next;
    }
    return count;
}

string Queue::getAllEMployee(){
    string text="";
    Node *tmp = fptr;
    while(tmp){
        text+= "Name : " + tmp->employee.getName()+"\n";
        text+= "Salary : " + to_string(tmp->employee.getSalary())+"\n";
        text+= "Position : " + tmp->employee.getPosition()+"\n";
        text+= "Performance : " + to_string(tmp->employee.getPerformanceStatus())+"\n";
        text+= "Number of Leaves : " + to_string(tmp->employee.getNumOfLeave())+"\n\n";
        text+= "==========================================================================\n\n";
        tmp = tmp->next;
    }
    return text;
}
