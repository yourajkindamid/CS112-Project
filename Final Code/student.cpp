#include "Student.h"
#include "Admin.h"
#include <iostream>

Student::Student() {}

Student::Student(string name, string email, string username, string password, string id)
    : User(name, email, username, password) 
{
    studentId = id;
}

Student::~Student() {}

string Student::getStudentId() 
{
    return studentId;
}

void Student::setStudentId(string id) 
{
    studentId = id;
}

void Student::enrollInCourse(string courseName) 
{
    enrolledCourses.push_back(courseName);
    cout << "Enrolled in: " << courseName << endl;
}

void Student::viewCourses() 
{
    cout << "\nEnrolled Courses:\n";
    if (enrolledCourses.empty()) {
        cout << "You are not enrolled in any courses yet.\n";
        return;
    }
    
    for (int i = 0; i < enrolledCourses.size(); i++) {
        cout << i+1 << ". " << enrolledCourses[i] << endl;
    }
}

void Student::displayInfo() 
{
    cout << "Student Name: " << name << ", ID: " << studentId << ", Email: " << email << endl;
}

string Student::getUserType()
{
    return "Student";
}

void Student::setMessBill(double amount) 
{
    messBill = amount;
}

double Student::getMessBill() const 
{
    return messBill;
}

void Student::paymessbill()
{
    if (messBill == 0) 
    {
        cout << "You have no pending mess bill to pay." << endl;
        return;
    }

    cout << "Your current mess bill is: $" << messBill << endl;
    cout << "Enter amount to pay: ";
    double amount;
    cin >> amount;

    if (amount == messBill)
    {
        messBill = 0;
        cout << "Your bill has been successfully paid." << endl;
    }
    else
    {
        cout << "Incorrect amount. Please pay the full bill amount." << endl;
    }
}


void Student::performActions(vector<Course*>& courses) 
{
    int choice = 0;
    bool exit = false;
    
    while (!exit) {
        cout << "\n===== Student Menu =====\n";
        cout << "1. View my profile\n";
        cout << "2. View enrolled courses\n";
        cout << "3. Enroll in a course\n";
        cout << "4. Pay mess bill\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                displayInfo();
                break;
                
            case 2:
                viewCourses();
                break;
                
            case 3:
                cout << "\nAvailable Courses:\n";
                for (int i = 0; i < courses.size(); i++) {
                    cout << i+1 << ". " << courses[i]->getCourseName() << endl;
                }
                
                int courseChoice;
                cout << "Enter course number to enroll (0 to cancel): ";
                cin >> courseChoice;
                
                if (courseChoice > 0 && courseChoice <= courses.size()) {
                    Course* selectedCourse = courses[courseChoice-1];
                    enrollInCourse(selectedCourse->getCourseName());
                    selectedCourse->addStudent(this);
                }
                break;
                
            case 4:
                paymessbill();
                break;

            case 5:
                exit = true;
                cout << "Exiting student menu.\n";
                break;
                
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

