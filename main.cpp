#include "Student.h"

#include <iostream>
#include <string>
#include <strstream>

using namespace std;

static bool validateInput(const string& s) {
    if (s.empty())
        return false;
    for (int i = 0; i < s.length(); i++) {
        if (isspace(s[i]))
            return false;
    }
    return true;
}


int main() {
    bool endProgram = false;
    while (!endProgram) {
        // get user input
        string name;
        do {
            cout << "Enter the first name of Student 1: " << endl;
            getline(cin, name);

            if (!validateInput(name))
                cout << "Name cannot be blank or contain spaces" << endl;
        } while (!validateInput(name));

        // instantiate student
        Student stu1(name);

        // set input string back to null
        name.clear();

        string course;
        while (course != "exit") {
            course.clear(); // set input string back to null

            do {
                // get course from user
                cout << "Enter course for " << stu1.getName() << "(or \"exit\", if done): " << endl;
                getline(cin, course);

                if (!validateInput(course)) {// needs work (whitespace)
                    cout << "Course cannot be blank or contain spaces" << endl;
                }
            } while (!validateInput(course));

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

        // display student 2
        cout << stu2 << endl;

        // drop courses from student 1
        stu1.flunkOut();

        cout << stu1 << "\n" << stu2 << endl;

        // assign student 2 to student 3
        Student stu3;

        stu3 = stu2;

        cout << stu3 << endl;

        string input;
        cout << "Enter \"X\" to end program. Otherwise, press Enter to continue: " << endl;
        getline(cin, input);
        if (input == "X" or input == "x") {
            endProgram = true;
        }
    }
    return 0;
}
