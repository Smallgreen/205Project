#include <iostream>
#include "userbase.h"
#include "citizen.h"


using namespace std;

int UserBase::id = 0;

int main()
{
    Citizen *c = new Citizen;
    cout << "type is "  << c->userType<< endl;
    return 0;

}
