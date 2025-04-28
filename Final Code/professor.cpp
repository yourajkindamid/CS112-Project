#include "Professor.h"
#include <iostream>

Professor::Professor() {}

Professor::Professor(string name, string email, string username, string password, string id) : User(name, email, username, password) 
{
    professorId = id;
}

Professor::~Professor() {}

string Professor::getProfessorId() 
{
    return professorId;
}

void Professor::setProfessorId(string id) 
{
    professorId = id;
}

void Professor::addCourse(string courseName) 
{
    teachingCourses.push_back(courseName);
    cout << "Teaching: " << courseName << endl;
}

void Professor::viewCourses() 
{
    cout << "\nCourses taught by Professor " << name << ":\n";
    if (teachingCourses.empty()) {
        cout << "You are not teaching any courses yet.\n";
        return;
    }
    
    for (int i = 0; i < teachingCourses.size(); i++) 
    {
        cout << i+1 << ". " << teachingCourses[i] << endl;
    }
}

void Professor::displayInfo() 
{
    cout << "Professor Name: " << name << ", ID: " << professorId << ", Email: " << email << endl;
}

string Professor::getUserType() 
{
    return "Professor";
}

void Professor::performActions(vector<Course*>& courses) 
{
    int choice = 0;
    bool exit = false;
    
    while (!exit) 
    {
        cout << "\n===== Professor Menu =====\n";
        cout << "1. View my profile\n";
        cout << "2. View my courses\n";
        cout << "3. Create a new course\n";
        cout << "4. Manage existing course\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) 
        {
            case 1:
            displayInfo();
            break;
                
            case 2:
            viewCourses();
            break;
                
            case 3: 
            {
                string courseId, courseName;
                cin.ignore(); // Clear input buffer
                
                cout << "Enter course ID (e.g., CS101): ";
                getline(cin, courseId);
                
                cout << "Enter course name: ";
                getline(cin, courseName);
                
                Course* newCourse = new Course(courseId, courseName);
                courses.push_back(newCourse);
                addCourse(courseId);
                
                cout << "Course created successfully: " << courseId << " - " << courseName << endl;
                break;
            }
                
            case 4: 
            {
                viewCourses();
                
                if (teachingCourses.empty()) 
                {
                    break;
                }
                
                int courseChoice;
                cout << "Select course to manage (0 to cancel): ";
                cin >> courseChoice;
                
                if (courseChoice < 1 || courseChoice > teachingCourses.size()) 
                {
                    cout << "Invalid selection or operation cancelled.\n";
                    break;
                }
                
                // Find the selected course object
                Course* selectedCourse = nullptr;
                string selectedCourseName = teachingCourses[courseChoice-1];
                
                for (Course* course : courses) 
                {
                    if (course->getCourseId() == selectedCourseName) 
                    {
                        selectedCourse = course;
                        break;
                    }
                }
                
                if (!selectedCourse) 
                {
                    cout << "Course not found in system.\n";
                    break;
                }
                
                int managementChoice;
                cout << "\n--- Course Management Menu ---\n";
                cout << "1. View enrolled students\n";
                cout << "2. Update course name\n";
                cout << "3. Back to main menu\n";
                cout << "Enter choice: ";
                cin >> managementChoice;
                
                switch (managementChoice) 
                {
                    case 1:
                        cout << "\nStudents enrolled in " << selectedCourseName << ":\n";
                        selectedCourse->viewEnrolledStudents();
                        break;
                        
                    case 2: 
                    {
                        string newName;
                        cin.ignore();
                        cout << "Enter new course name: ";
                        getline(cin, newName);
                        selectedCourse->setCourseDescription(newName);
                        cout << "Course name updated successfully.\n";
                        break;
                    }
                        
                    case 3:
                        cout << "Returning to main menu.\n";
                        break;
                        
                    default:
                        cout << "Invalid choice.\n";
                }
                break;
            }
                
            case 5:
                exit = true;
                cout << "Exiting professor menu.\n";
                break;
                
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}