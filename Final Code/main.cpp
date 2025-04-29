#include <iostream>
#include <vector>
#include <string>
#include "user.cpp"
#include "course.cpp"
#include "student.cpp"
#include "signup.cpp"
#include "professor.cpp"
#include "admin.cpp"
#include "login.cpp"
#include <conio.h>
using namespace std;

int main()
{ 
    vector<User*> users;  
    vector<Course*> courses;  
    
    Course* course1 = new Course("CS101", "Introduction to Programming");
    Course* course2 = new Course("MATH201", "Advanced Calculus");
    Course* course3 = new Course("ENG101", "English Composition");
    
    courses.push_back(course1);
    courses.push_back(course2);
    courses.push_back(course3);

    const string STUDENT_CODE = "S001";
    const string PROFESSOR_CODE = "P001";
    const string ADMIN_CODE = "A001";

    
   

    while(true)
    {
        char ch;
        cout << "=== Welcome to the Learning Management System ===" << endl;
        ch =getch();
        system("cls");
        string name, email, username, password, userTypeCode;
        cout << "=== Sign Up ===" << endl;
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Email: ";
        getline(cin, email);
        cout << "Enter Username: ";
        getline(cin, username);
        cout << "Enter Password: ";
        getline(cin, password);
        cout << "Enter User Type Code: ";
        getline(cin, userTypeCode);


    User* newUser = nullptr;

    if (userTypeCode == STUDENT_CODE)
    {
        newUser = Signup::registerUser(users, name, email, username, password, "Student");
    }
    else if (userTypeCode == PROFESSOR_CODE) 
    {
        newUser = Signup::registerUser(users, name, email, username, password, "Professor");
    }
    else if (userTypeCode == ADMIN_CODE) 
    {
        newUser = Signup::registerUser(users, name, email, username, password, "Admin");
    } 
    else 
    {
        cout << "Invalid user type code! Registration failed." << endl;
        continue;
    }

    if (!newUser) 
    {
        cout << "User registration failed. Exiting." << endl;
        continue;
    }

    cout << "=== Login ===" << endl;
    cout << "Enter Username: ";
    getline(cin,username);
    cout << "Enter Password: ";
    getline(cin,password); 
    
    User* loggedInUser = Login::authenticate(users, username, password);
    if (!loggedInUser) 
    {
        cout << "Login failed. Exiting." << endl;
        cin.ignore();
        continue;
    }
    
    cout << "Welcome, " << loggedInUser->getUsername() << "!" << endl;
    cout << "User Type: " << loggedInUser->getUserType() << endl;
    
    if (loggedInUser->getUserType() == "Student")
    {
        Student* student = (Student*)loggedInUser;
        student->performActions(courses);
    }
    else if (loggedInUser->getUserType() == "Professor")
    {
        Professor* professor = (Professor*)loggedInUser;
        professor->performActions(courses);
    }
    else if (loggedInUser->getUserType() == "Admin")
    {
        Admin* admin = (Admin*)loggedInUser;
        admin->performActions(users);
    }

    char continueChoice;
    cout << "Do you want to sign up or log in again? ('y' for sign up and 'n' for logout): ";
    cin >> continueChoice;
    cin.ignore();

    if (continueChoice != 'y' && continueChoice != 'Y') 
    {
        system("cls");
        break;
    }
    }
    for (int i = 0; i < users.size(); i++)
    {
        delete users[i];
    }
    for (int i = 0; i < courses.size(); i++)
    {
        delete courses[i];
    }

    return 0;
}