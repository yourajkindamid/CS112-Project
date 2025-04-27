#include "Admin.h"
#include <iostream>

Admin::Admin() {}

Admin::Admin(string name, string email, string username, string password, string id)
    : User(name, email, username, password) 
{
    adminId = id;
}

Admin::~Admin() {}

string Admin::getAdminId() 
{
    return adminId;
}

void Admin::setAdminId(string id) 
{
    adminId = id;
}

bool Admin::addUser(User* user, vector<User*>& users) 
{
    users.push_back(user);
    cout << "User added: " << user->getUsername() << endl;
    return true;
}

bool Admin::removeUser(string username, vector<User*>& users) 
{
    for (int i = 0; i < users.size(); i++) 
    {
        if (users[i]->getUsername() == username) 
        {
            users.erase(users.begin() + i);
            cout << "User removed: " << username << endl;
            return true;
        }
    }
    return false;
}

void Admin::viewAllUsers(const vector<User*>& users) 
{
    cout << "All Users:\n";
    for (int i = 0; i < users.size(); i++) 
    {
        cout << users[i]->getUsername() << " (" << users[i]->getUserType() << ")" << endl;
    }
}

bool Admin::assignMessBill(string studentId, double amount) 
{
    cout << "Assigned mess bill of $" << amount << " to student " << studentId << endl;
    return true;
}

void Admin::displayInfo() 
{
    cout << "Admin Name: " << name << ", ID: " << adminId << ", Email: " << email << endl;
}

string Admin::getUserType() 
{
    return "Admin";
}

void Admin::performActions(vector<User*>& users)
{
    cout << "\nAdmin Actions:\n";
    viewAllUsers(users);
}
