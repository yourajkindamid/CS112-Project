#pragma once

#include <string>
#include <vector>
#include "Student.h"

using namespace std;

class Course 
{
    private:
    string courseId;
    string courseName;
    string courseDescription;
    vector<Student*> enrolledStudents;

    public:
    Course();
    Course(string id, string name);
    ~Course();

    string getCourseId();
    string getCourseName();
    
    void addStudent(Student* student);
    void removeStudent(Student* student);
    void viewEnrolledStudents();
    void setCourseDescription(const string& description);

    void displayCourseInfo();
};