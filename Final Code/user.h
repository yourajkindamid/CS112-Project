#pragma once

#include <string>
using namespace std;

class User 
{
    protected:
    string name;
    string email;
    string username;
    string password;

    public:
    User();
    User(string name, string email, string username, string password);
    virtual ~User();

    string getName();
    string getEmail();
    string getUsername();
    string getPassword();

    void setName(string name);
    void setEmail(string email);
    void setUsername(string username);
    void setPassword(string password);

    virtual void displayInfo();
    virtual string getUserType();
};