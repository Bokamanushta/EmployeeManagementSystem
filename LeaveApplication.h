#ifndef LEAVEAPPLICATION_H
#define LEAVEAPPLICATION_H
#include <string>
using namespace std;
class LeaveApplication
{
private:
    string Name;
    string mc;
    string application_status;

public:
    // Constructors
    LeaveApplication();
    LeaveApplication(string, string, string);

    // Mutators;
    void setName(string);
    void setMC(string);
    void setApplicationStatus(string);

    //Accessors
    string getName() const;
    string getMC() const;
    string getApplicationStatus() const;
};

#endif // LEAVEAPPLICATION_H
