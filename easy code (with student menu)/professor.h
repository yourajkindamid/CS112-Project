#pragma once

#include "User.h"
#include <vector>
#include <string>

using namespace std;


class Course;

class Professor : public User 
{
    private:
    string professorId;
    vector<string> teachingCourses;

    public:
    Professor();
    Professor(string name, string email, string username, string password, string id);
    virtual ~Professor();

    string getProfessorId();
    void setProfessorId(string id);

    void addCourse(string courseName);
    void viewCourses();

    void displayInfo();
    string getUserType();
    void performActions(vector<Course*>& courses);
};