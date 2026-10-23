#include "Student.h"

#include <iostream>
#include <string>
#include <strstream>

using namespace std;

int main() {

    // get user input
    string name;
    cout << "Enter the name of Student 1: " << endl;
    getline(cin, name);

    // instantiate student
    auto stu1 = Student(name);

    // set input string back to null
    name.clear();

    string course;
    while (course != "exit") {
        course.clear(); // set input string back to null

        bool isValid = true;
        do {
            // get course from user
            cout << "Enter course for " << stu1.getName() << "(or \"exit\", if done): " << endl;
            getline(cin, course);
            if (course.empty()) {// needs work (whitespace)
                isValid = false;
                cout << "Must enter a course" << endl;
            }
        } while (!isValid);
        // if not exit or empty, add to student
        if (course != "exit")
            stu1.add(course);
    }

    // show student 1 info
    cout << stu1 << endl;

    // begin student 2 w/ copy constructor
    auto stu2 = Student(stu1);

    // replace name
    cout << "Enter the name of Student 2: " << endl;
    getline(cin, name);
    stu2.setName(name);

    return 0;
}
