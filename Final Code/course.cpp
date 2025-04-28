#include "Course.h"
#include <iostream>

Course::Course() {}

Course::Course(string id, string name) 
{
    courseId = id;
    courseName = name;
    courseDescription = "";
}

Course::~Course() {}

string Course::getCourseId() 
{
    return courseId;
}

string Course::getCourseName() 
{
    return courseName;
}

void Course::addStudent(Student* student) 
{
    enrolledStudents.push_back(student);
    cout << "Student " << student->getUsername() << " added to course " << courseName << endl;
}

void Course::removeStudent(Student* student) 
{
    for (int i = 0; i < enrolledStudents.size(); i++) 
    {
        if (enrolledStudents[i] == student) 
        {
            enrolledStudents.erase(enrolledStudents.begin() + i);
            cout << "Student " << student->getUsername() << " removed from course " << courseName << endl;
            return;
        }
    }
}

void Course::viewEnrolledStudents() 
{
    cout << "Enrolled Students in " << courseName << ":\n";
    for (int i = 0; i < enrolledStudents.size(); i++) {
        cout << "- " << enrolledStudents[i]->getUsername() << endl;
    }
}

void Course::displayCourseInfo() 
{
    cout << "Course ID: " << courseId << ", Name: " << courseName << endl;
}

void Course::setCourseDescription(const std::string& description) 
{
    courseDescription = description;
}
