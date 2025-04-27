#include "Student.h"
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
    cout << "Enrolled Courses:\n";
    for (int i = 0; i < enrolledCourses.size(); i++) {
        cout << "- " << enrolledCourses[i] << endl;
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

void Student::performActions(vector<Course*>& courses) 
{
    viewCourses();

    // Enroll in a new course
    Course* course1 = new Course("CS101", "Introduction to Programming");
    courses.push_back(course1);
    course1->addStudent(this);
    enrollInCourse("CS101");

    viewCourses();
}