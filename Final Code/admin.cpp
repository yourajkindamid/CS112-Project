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

//bool Admin::assignMessBill(string studentId, double amount) 
//{
//    cout << "Assigned mess bill of $" << this->amount << " to student " << studentId << endl;
//    return true;
//}

bool Admin::assignMessBill(string studentId, vector<User*>& users, double amount) 
{
    for (User* user : users) 
    {
       if (user->getUserType() == "Student") 
     {
        Student* student = dynamic_cast<Student*>(user);
            if (student && student->getStudentId() == studentId) 
            {
               student->setMessBill(amount);
                cout << "Assigned mess bill of $" << amount << " to student " << studentId << endl;
                return true;
            }
        }
    }
    cout << "Student with ID " << studentId << " not found!" << endl;
    return false;
}

void Admin::displayInfo() 
{
    cout << "Admin Name: " << name << ", ID: " << adminId << ", Email: " << email << endl;
}

string Admin::getUserType() 
{
    return "Admin";
}

void Admin::adminMenu(vector<User*>& users) 
{
    int choice;
    do 
    {
        cout << "\n--- Admin Menu ---\n";
        cout << "1. View all users\n";
        cout << "2. Add new user\n";
        cout << "3. Remove a user\n";
        cout << "4. Assign mess bill to student\n";
        cout << "5. Display admin info\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                viewAllUsers(users);
                break;
            case 2: 
            {
                string name, email, username, password, id, userType;
                cout << "Enter user type (Student/Professor): ";
                cin >> userType;
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter email: ";
                cin >> email;
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                cout << "Enter ID: ";
                cin >> id;
                if (userType == "Student") {
                    User* student = new Student(name, email, username, password, id);
                    addUser(student, users);
                } else if (userType == "Professor") {
                    User* professor = new Professor(name, email, username, password, id);
                    addUser(professor, users);
                }
                break;
            }
            case 3: 
            {
                string username;
                cout << "Enter the username to remove: ";
                cin >> username;
                if (!removeUser(username, users)) {
                    cout << "User not found.\n";
                }
                break;
            }
            case 4: 
            {
                string studentId;
                double amount;
                cout << "Enter student ID: ";
                cin >> studentId;
                cout << "Enter mess bill amount: ";
                cin >> amount;
                assignMessBill(studentId, users, amount);
                break;
            }
            case 5:
                displayInfo();
                break;
            case 6:
                cout << "Exiting Admin Menu...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 6);
}

void Admin::performActions(vector<User*>& users)
{
    adminMenu(users);
}
