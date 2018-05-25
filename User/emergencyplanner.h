#ifndef EMERGENCYPLANNER_H
#define EMERGENCYPLANNER_H

#include "userbase.h"
#include <iostream>

class EmergencyPlanner:public UserBase
{
public:

    EmergencyPlanner():UserBase("emergencyPlanner"){}


    void setUsername(string name){
        username = name;
    }
    void setPassword(string pword){
        password = pword;
    }
    void setPhone(int phoneNum){
        phone = phoneNum;
    }
    void setEmail(string emailAddress){
        email = emailAddress;
    }
};

#endif // EMERGENCYPLANNER_H
