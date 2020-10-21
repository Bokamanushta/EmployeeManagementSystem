
#include "Employee.h"

Employee::Employee() {}

Employee::Employee(string n, double s, string pos, bool pros, int performs, LeaveApplication app, int num)
{
    Name = n;
    salary = s;
    position = pos;
    promotion_status = pros;
    performance_status = performs;
    application = app;
    numOfLeave = num;
}

void Employee::setName(string n) { Name = n; }
void Employee::setSalary(double s) { salary = s; }
void Employee::setPosition(string pos) { position = pos; }
void Employee::setPromotionStatus(bool pros) { promotion_status = pros; }
void Employee::setPerformanceStatus(int performs) { performance_status = performs; }
void Employee::setNumOfLeave(int num) { numOfLeave = num; }

string Employee::getName() const { return Name; }
double Employee::getSalary() const { return salary; }
string Employee::getPosition() const { return position; }
bool Employee::getPromotionStatus() const { return promotion_status; }
int Employee::getPerformanceStatus() const { return performance_status; }
int Employee::getNumOfLeave() const { return numOfLeave; }
LeaveApplication Employee::getLeaveApplication() const{return application;}
LeaveApplication* Employee::getLeave(){return &application;}

void Employee::applyForLeave(string) {}
