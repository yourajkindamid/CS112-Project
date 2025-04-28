#pragma once

#include "User.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Admin : public User 
{
private:
    string adminId;
    double amount;

public:
    Admin();
    Admin(string name, string email, string username, string password, string id);
    virtual ~Admin();

    string getAdminId();
    void setAdminId(string id);

    bool addUser(User* user, vector<User*>& users);
    bool removeUser(string username, vector<User*>& users);
    void viewAllUsers(const vector<User*>& users);

    bool assignMessBill(string studentId, vector<User*>& users, double amount);

    void displayInfo();
    string getUserType();
    void performActions(vector<User*>& users);
    void adminMenu(vector<User*>& users);
};
