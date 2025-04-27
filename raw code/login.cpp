#include "Login.h"
#include <iostream>

User* Login::authenticate(vector<User*>& users, string username, string password) 
{
    for (int i = 0; i < users.size(); i++) 
    {
        if (users[i]->getUsername() == username && users[i]->getPassword() == password) 
        {
            cout << "Login successful!" << endl;
            return users[i];
        }
    }
    cout << "Invalid username or password." << endl;
    return nullptr;
}
