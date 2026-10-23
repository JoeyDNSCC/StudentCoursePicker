#include "Student.h"

#include <iostream>
#include <string>
#include <strstream>


// default constructor
Student::Student()
        :numCourses(0), courseList(nullptr) {
        std::cout << "created empty student" << std::endl;
    }

// string constructor
Student::Student(std::string name)
        :name(name), numCourses(0), courseList(nullptr) {
        std::cout << "created student with name" << std::endl;
    }

// copy constructor
Student::Student(Student& student)
    :name(student.name), numCourses(student.numCourses) {

    std::string* temp = new std::string[numCourses];// instance arr

    // TEST deep/shallow copy?
    for (int i = 0; i < student.numCourses; i++) {
        temp[i] = (student.courseList[i]);
    }
    delete[] courseList;
    courseList = temp;
    std::cout << "copied student " << student.name << std::endl;
}

// assignment operator
Student &Student::operator=(const Student &rightObj) {
    // in case assigned to itself
    if (this == &rightObj) return *this;

    // allocate memory for new array
    std::string* temp = new std::string[numCourses];

    // copy courses
    for (int i = 0; i < numCourses; i++) {
        temp[i] = rightObj.courseList[i];
    }

    delete[] courseList; // delete old array

    // assign new array & size to this object
    courseList = temp;
    numCourses = rightObj.numCourses;

    return *this;
}

// destructor
Student::~Student() {
        delete[] courseList;
    }

// add course to student
void Student::add(std::string course) {
    // increment
    this->numCourses++;
    std::string* newCourses = new std::string[numCourses];
    for (int i = 0; i < numCourses - 1; i++) {
        newCourses[i] = courseList[i];
    }


}

// output name and all courses
std::string Student::toString() {
    std::strstream strStream;
    strStream << this->name << std::endl;
    for (int i = 0; i < this->numCourses; i++) {
        strStream << this->courseList[i] << std::endl;
    }
    return strStream.str(); // THIS FUNCTION IS WRONG
}

// overloaded << operator
std::ostream &operator<<(std::ostream &output, Student &student) {
    output << student.toString();
}

