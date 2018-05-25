#ifndef CITIZEN_H
#define CITIZEN_H
#include "userbase.h"
#include <iostream>

using namespace std;


class Citizen:public UserBase
{
public:
    Citizen():UserBase("citizen"){}


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

#endif // CITIZEN_H
