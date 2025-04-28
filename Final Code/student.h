#pragma once

#include "User.h"
#include <vector>
#include <string>

using namespace std;

class Course;

class Student : public User 
{
    private:
    string studentId;
    vector<string> enrolledCourses;
    double messBill = 0.0;
    
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

    void setMessBill(double amount);
    void paymessbill();
    double getMessBill() const;

    void performActions(vector<Course*>& courses);
};
