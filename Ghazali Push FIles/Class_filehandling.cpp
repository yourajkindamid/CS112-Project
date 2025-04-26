#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileHandler {
public:

    static void saveUser(const string &type, const string &name, const string &email, const string &username, const string &password) {
        ofstream file("users.txt", ios::app);
        file << "Type: " << type << " ,Name: " << name << " ,Email: " << email << " ,Username: " << username << " & Password: " << password << "\n";
        file.close();
    }

    static bool loadUser(const string &username, const string &password, string &type) {
        ifstream file("users.txt");
        string t, name, email, u, p;
        while (file >> t >> name >> email >> u >> p) {
            if (u == username && p == password) {
                type = t;
                return true;
            }
        }
        return false;
    }

    static void saveCourse(const string &courseCode, const string &courseName) {
        ofstream file("courses.txt", ios::app);
        file <<"Course Code: " << courseCode << " ,Course Name: " << courseName << "\n";
        file.close();
    }

    static void saveGrade(const string &studentID, const string &courseCode, float Percentage, string Grade) {
        ofstream file("grades.txt", ios::app);
        file <<"Student ID: " << studentID << " ,Course Code: " << courseCode << " ,Percentage: " << Percentage << " &Grade: " << Grade << "\n";
        file.close();
    }

    static void showGrade(const string &studentID, const string &courseCode)
{
    ifstream file("grades.txt"); 

    if (!file) {
        cout << "File could not be opened for reading!\n";
        return;
    }

    string line; 
    cout << "Contents of file:\n";

    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

    static void saveAttendance(const string &studentID, const string &courseCode, bool attended) {
        string attendanceStatus = attended ? "Present" : "Absent";
        
        ofstream file("attendance.txt", ios::app);
        
        file <<"Student ID: " << studentID << " ,Course Code: " << courseCode << " &Attendance: " << attendanceStatus << "\n";
        
        file.close();
    }

    static void showAttendance(const string &studentID, const string &courseCode)
{
    ifstream file("attendance.txt");

    if (!file) {
        cout << "File could not be opened for reading!\n";
        return;
    }

    string id, course, status;
    bool found = false;

    cout << "Attendance Record:\n";
    while (file >> id >> course >> status) {
        if (id == studentID && course == courseCode) {
            cout << "Student ID: " << id << " ,Course: " << course << " ,Status: " << status << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No attendance record found for this student and course.\n";
    }

    file.close();
}
    static void saveMessBill(const string &studentID, float billAmount) {
        ofstream file("mess.txt", ios::app);
        file <<"Student ID: " << studentID << " ,Bill Amount: " << billAmount << "\n";
        file.close();
    }
};
int main() {
    int choice;
    string type, name, email, username, password;
    string courseCode, courseName, Grade;
    string studentID;
    float Percentage, billAmount;
    bool attended;

    do {
        cout << "\n--- FileHandler Test Menu ---\n";
        cout << "1. Save User\n";
        cout << "2. Login User\n";
        cout << "3. Save Course\n";
        cout << "4. Save Grade\n";
        cout << "5. Show Grade\n";            
        cout << "6. Save Attendance\n";
        cout << "7. Show Attendance\n";        
        cout << "8. Save Mess Bill\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter type (Admin/Professor/Student): ";
                cin >> type;
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter email: ";
                cin >> email;
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                FileHandler::saveUser(type, name, email, username, password);
                cout << "User saved.\n";
                break;

            case 2:
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                if (FileHandler::loadUser(username, password, type)) {
                    cout << "Login successful! User type: " << type << "\n";
                } else {
                    cout << "Login failed.\n";
                }
                break;

            case 3:
                cout << "Enter course code: ";
                cin >> courseCode;
                cout << "Enter course name: ";
                cin >> courseName;
                FileHandler::saveCourse(courseCode, courseName);
                cout << "Course saved.\n";
                break;

            case 4:
                cout << "Enter student ID: ";
                cin >> studentID;
                cout << "Enter course code: ";
                cin >> courseCode;
                cout << "Enter Percentage marks: ";
                cin >> Percentage;
                cout << "Enter Grade: ";
                cin >> Grade;
                FileHandler::saveGrade(studentID, courseCode, Percentage, Grade);
                cout << "Grade saved.\n";
                break;

            case 5:
                cout << "Enter student ID: ";
                cin >> studentID;
                cout << "Enter course code: ";
                cin >> courseCode;
                FileHandler::showGrade(studentID, courseCode);
                break;

            case 6:
                cout << "Enter student ID: ";
                cin >> studentID;
                cout << "Enter course code: ";
                cin >> courseCode;
                cout << "Attended (1 for yes, 0 for no): ";
                cin >> attended;
                FileHandler::saveAttendance(studentID, courseCode, attended);
                cout << "Attendance saved.\n";
                break;

            case 7:
                cout << "Enter student ID: ";
                cin >> studentID;
                cout << "Enter course code: ";
                cin >> courseCode;
                FileHandler::showAttendance(studentID, courseCode);
                break;

            case 8:
                cout << "Enter student ID: ";
                cin >> studentID;
                cout << "Enter mess bill amount: ";
                cin >> billAmount;
                FileHandler::saveMessBill(studentID, billAmount);
                cout << "Mess bill saved.\n";
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
