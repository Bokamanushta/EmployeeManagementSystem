
#include "LeaveApplication.h"

LeaveApplication::LeaveApplication(){};

LeaveApplication::LeaveApplication(string n, string m, string s)
{
    Name = n;
    mc = m;
    application_status = s;
}

void LeaveApplication::setName(string n) { Name = n; }
void LeaveApplication::setMC(string m) { mc = m; }
void LeaveApplication::setApplicationStatus(string s) { application_status = s; }

string LeaveApplication::getName() const { return Name; }
string LeaveApplication::getMC() const { return mc; }
string LeaveApplication::getApplicationStatus() const { return application_status; }
