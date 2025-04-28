#pragma once

#include <string>
#include <vector>
#include "User.h"

using namespace std;

class Signup 
{
    public:
    static User* registerUser(vector<User*>& users, string name, string email, string username, string password, string userType);
};
