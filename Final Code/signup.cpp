#include "Signup.h"
#include "Student.h"
#include "Professor.h"
#include "Admin.h"
#include <iostream>

User* Signup::registerUser(vector<User*>& users, string name, string email, string username, string password, string userType) 
{
    User* newUser = nullptr;

    if (userType == "Student") 
    {
        newUser = new Student(name, email, username, password, "Student" + username);  // Assigning a simple ID
    } 
    else if (userType == "Professor") 
    {
        newUser = new Professor(name, email, username, password, "Professor" + username);
    } 
    else if (userType == "Admin") 
    {
        newUser = new Admin(name, email, username, password, "Admin" + username);
    } 
    else 
    {
        cout << "Invalid user type!" << endl;
        return nullptr;
    }

    users.push_back(newUser);
    cout << "User Registered" << endl;
    return newUser;
}
