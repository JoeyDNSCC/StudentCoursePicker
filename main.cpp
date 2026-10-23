#include <iostream>

#include "Student.h"


using namespace std;

int main() {

    // get user input
    string name;
    cout << "Enter the name of Student 1: " << endl;
    getline(cin, name);

    // instance obj
    auto stu1 = Student(name);


    string course;
    // maybe switch to while?
    for (int i = 0; course != "exit"; i++) {
        // get course from user
        cout << "Enter course for " << stu1.getName() << "(or \"exit\", if done): " << endl;
        getline(cin, course);

        // if not exit or empty, add to student
        if (course != "exit" && !course.empty()) // needs work (whitespace)
            stu1.add(course);
    }


    return 0;
}
