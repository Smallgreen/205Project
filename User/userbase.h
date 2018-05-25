#ifndef USERBASE_H
#define USERBASE_H
#include <iostream>

using namespace std;

class UserBase
{
public:

    //citizen = 0; fr = 1; ep = 2;
    //enum userTypes{citizen, firstResponder, emergencyPlanner};
    string userType;

    UserBase(string uType){
        userType = uType;
        userId = id;
        id++;
    }

    virtual void setUsername(string name){}
    virtual void setPassword(string pword){}
    virtual void setPhone(int phoneNum){}
    virtual void setEmail(string emailAddress){}

    int userId;

protected:
    string username;
    string password;
    int phone;
    static int id;

    string email;

};

#endif // USERBASE_H
