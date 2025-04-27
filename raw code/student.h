#pragma once

#include "User.h"
#include <vector>
#include <string>

using namespace std;

class Course;

class Student : public User {
private:
    string studentId;
    vector<string> enrolledCourses;

public:
    Student();
    Student(string name, string email, string username, string password, string id);
    virtual ~Student();

    string getStudentId();
    void setStudentId(string id);

    void enrollInCourse(string courseName);
    void viewCourses();

    void displayInfo();
    string getUserType();

    void performActions(vector<Course*>& courses);
};
