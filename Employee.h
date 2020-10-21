#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include "LeaveApplication.h"
using namespace std;
class Employee
{
private:
    string Name;
    double salary;
    string position;
    bool promotion_status;
    int performance_status;
    LeaveApplication application;
    int numOfLeave;

public:
    // Constructors
    Employee();
    Employee(string, double, string, bool, int, LeaveApplication, int);

    // Mutators
    void setName(string);
    void setSalary(double);
    void setPosition(string);
    void setPromotionStatus(bool);
    void setPerformanceStatus(int);
    void setNumOfLeave(int);

    //Accessors
    string getName() const;
    double getSalary() const;
    string getPosition() const;
    bool getPromotionStatus() const;
    int getPerformanceStatus() const;
    int getNumOfLeave() const;
    LeaveApplication getLeaveApplication() const;
    LeaveApplication* getLeave();
    // Method
    void applyForLeave(string);
};
#endif // EMPLOYEE_H
