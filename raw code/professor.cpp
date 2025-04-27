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
    cout << "Courses taught by Professor " << name << ":\n";
    for (int i = 0; i < teachingCourses.size(); i++) 
    {
        cout << "- " << teachingCourses[i] << endl;
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
    viewCourses();

    // Create a new course
    Course* course1 = new Course("CS201", "Data Structures");
    courses.push_back(course1);
    addCourse("CS201");

    viewCourses();
}