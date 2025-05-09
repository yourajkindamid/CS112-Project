#include "User.h"
#include <iostream>

User::User() {}

User::User(string name, string email, string username, string password) 
{
    this->name = name;
    this->email = email;
    this->username = username;
    this->password = password;
}

User::~User() {}

string User::getName() 
{
    return name;
}

string User::getEmail() 
{
    return email;
}

string User::getUsername() 
{
    return username;
}

string User::getPassword() 
{
    return password;
}

void User::setName(string name) 
{
    this->name = name;
}


void User::setEmail(string email)       //we are recieving the required data through the constructor. we only need the setters if we plan on changing the data recieevd and for encapsulation
{
    this->email = email;
}

void User::setUsername(string username) 
{
    this->username = username;
}

void User::setPassword(string password) 
{
    this->password = password;
}

void User::displayInfo() 
{
    cout << "Name: " << name << ", Email: " << email << endl;
}

string User::getUserType() 
{
    return "User";
}
