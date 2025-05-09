#include "Course.h"
#include <iostream>

Course::Course() {}

Course::Course(string id, string name)      // If you dont passs coursedescription from outside, but still assign it manually (like above), your code works fine
{
    courseId = id;
    courseName = name;
    courseDescription = "";         // you are setting a defult value(empty string), which is perfectly fine
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

void Course::addStudent(Student* student) //Student* student is a student class pointer which dynamically allocated 
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
        cout << "- " << enrolledStudents[i]->getUsername() << endl;  //as as enrolledStudent is a vector that is stroring Student*
    }                                                                 //pointers, you need to dereference the pointer to accessthe Student object
}

void Course::displayCourseInfo() 
{
    cout << "Course ID: " << courseId << ", Name: " << courseName << endl;
}

void Course::setCourseDescription(const std::string& description) 
{
    courseDescription = description;   //const The function can't modify the string
}                                       //string& is a reference and it avids copying the whole string
                                        //const string& is efficient and safe, as no copy can be made and cannot be changed accidentally
