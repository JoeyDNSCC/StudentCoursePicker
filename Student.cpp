#include "Student.h"

#include <iostream>
#include <string>
#include <strstream>
#include <utility>


// default constructor
Student::Student()
        :numCourses(0), courseList(nullptr) {
        std::cout << "created empty student" << std::endl;
    }

// string constructor
Student::Student(std::string name)
        :name(std::move(name)), numCourses(0), courseList(nullptr) {
        std::cout << "created student with name" << std::endl;
    }

// copy constructor
Student::Student(const Student& student)
    // copy name and numCourses
    :name(student.name), numCourses(student.numCourses) {

    std::cout << "BEGAN copy_constructor " << student.name << std::endl;

    // instance array to hold courses
    this->courseList = new std::string[numCourses];

    // copy courses from passed student to created student
    for (int i = 0; i < student.numCourses; i++) {
        this->courseList[i] = (student.courseList[i]);
    }

    std::cout << "COMPLETE copy_constructor " << student.name << std::endl;
}

// assignment operator
Student& Student::operator=(const Student &rightObj) {
    // in case assigned to itself
    if (this == &rightObj) return *this;

    // allocate memory for new array
    auto* temp = new std::string[numCourses];

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
void Student::add(const std::string& course) {

    // increment array length
    this->numCourses++;
    // create temp array with new length
    auto* newCourses = new std::string[numCourses];

    //fill new array with old values
    for (int i = 0; i < numCourses - 1; i++) {
        newCourses[i] = courseList[i];
    }
    // insert new value at end
    newCourses[numCourses - 1] = course;

    // replace old array with new array
    delete[] courseList;
    courseList = newCourses;
}

// output name and all courses (broken?)
std::string Student::toString() const {
    // feels like cheating bcuz strings change size dynamically
    std::string output;
    // basic output string building
    output.append(this->name + " is in:\n");
    for (int i = 0; i < this->numCourses; i++) {
        output.append(this->courseList[i] + ", "); // TO-DO: fix trailing comma
    }
    return output;
}

// overloaded << operator
std::ostream& operator<<(std::ostream &output, const Student &student) {
    output << student.toString();
    return output; //ostream object

}

// ==============================
// getters & setters

std::string Student::getName() const {
    return name;
}
int Student::getNumCourses() const {
    return numCourses;
}
std::string Student::getCourse(int index) const {
    if (index < 0 || index >= numCourses) {
        throw std::out_of_range("Invalid course index");
    }
    return courseList[index];
}


