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
using namespace std;

int main()
{ 
    vector<User*> users;  // Store all users in the system
    vector<Course*> courses;  // Store all courses in the system

    // Create some sample courses for testing the student menu
    Course* course1 = new Course("CS101", "Introduction to Programming");
    Course* course2 = new Course("MATH201", "Advanced Calculus");
    Course* course3 = new Course("ENG101", "English Composition");
    
    courses.push_back(course1);
    courses.push_back(course2);
    courses.push_back(course3);

    const string STUDENT_CODE = "S001";
    const string PROFESSOR_CODE = "P001";
    const string ADMIN_CODE = "A001";

    cout << "=== Welcome to the Learning Management System ===" << endl;

    // Sign Up Process
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
    cout << "Enter User Type Code (Student: S001, Professor: P001, Admin: A001): ";
    getline(cin, userTypeCode);


    User* newUser = nullptr;

    // Check user type code and create user accordingly
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
        return 0;
    }

    if (!newUser) 
    {
        cout << "User registration failed. Exiting." << endl;
        return 0;
    }

    // Login Process
    cout << "=== Login ===" << endl;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;
    
    User* loggedInUser = Login::authenticate(users, username, password);
    if (!loggedInUser) 
    {
        cout << "Login failed. Exiting." << endl;
        return 0;
    }
    
    cout << "Welcome, " << loggedInUser->getUsername() << "!" << endl;
    cout << "User Type: " << loggedInUser->getUserType() << endl;
    
    if (loggedInUser->getUserType() == "Student")
    {
        Student* student = (Student*)loggedInUser;
        // Pass the courses vector to the student's performActions method
        student->performActions(courses);
    }
    else if (loggedInUser->getUserType() == "Professor")
    {
        Professor* professor = (Professor*)loggedInUser;  // Treating as a Professor object
        professor->performActions(courses);  // Call the performActions method for Professor
    }
    else if (loggedInUser->getUserType() == "Admin")
    {
        Admin* admin = (Admin*)loggedInUser;  // Treating as an Admin object
        admin->performActions(users);  // Call the performActions method for Admin
    }

    // Clean up memory
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