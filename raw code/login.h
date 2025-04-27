#pragma once
#include <string>
#include <vector>
#include "User.h"

using namespace std;

class Login 
{
public:
    static User* authenticate(vector<User*>& users, string username, string password);
};
