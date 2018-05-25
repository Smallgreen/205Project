#ifndef FIRSTRESPONDER_H
#define FIRSTRESPONDER_H
#include "userbase.h"
#include <iostream>


class FirstResponder:public UserBase
{
public:
    FirstResponder():UserBase("First Responder"){}


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

#endif // FIRSTRESPONDER_H
