#include "Student.h"

#include <iostream>
#include <string>
#include <strstream>
#include <utility>


// default constructor
Student::Student()
    :numCourses(0), courseList(nullptr) {
    std::cout << "defaultConstructor" << std::endl;
}

// string constructor
Student::Student(std::string name)
    :name(std::move(name)), numCourses(0), courseList(nullptr) {
    std::cout << "string_constructor" << std::endl;
}

// copy constructor
Student::Student(const Student& student)
    // copy name and numCourses
    :name(student.name), numCourses(student.numCourses) {

    std::cout << "copy_constructor " << student.name << std::endl;

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
    std::cout << "BEGAN assignment_operator_overload" << std::endl;

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

    std::cout << "COMPLETE assignment_operator_overload" << std::endl;

    return *this;
}

// destructor
Student::~Student() {
    std::cout << "BEGAN destructor" << std::endl;
    // if (courseList != nullptr) // ask abt redundant null check
    delete[] courseList;
    std::cout << "COMPLETE destructor" << std::endl;
}

// add course to student
void Student::add(const std::string& course) {
    std::cout << "BEGAN add_course" << std::endl;
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
    std::cout << "COMPLETE add_course" << std::endl;
}

// output name and all courses (broken?)
std::string Student::toString() const {

    // feels like cheating bcuz strings change size dynamically
    std::string output;

    // basic output string building
    output.append(this->name + " is in " + std::to_string(this->numCourses) +" course(s):\n");

    // wasting time coding oxford comma condition
    if (numCourses == 1) {
        output.append(courseList[0]);
    } else if (numCourses == 2) {
        output.append(courseList[0] + " and " + courseList[1]);
    } else {
        for (int i = 0; i < numCourses - 1; i++) {
            output.append(courseList[i] + ", ");
        }
        output.append("and " + courseList[numCourses - 1]);
    }

    return output;
}

// overloaded << operator
std::ostream& operator<<(std::ostream &output, Student &student) {
    std::cout << "BEGAN ostream_operator_overload" << std::endl;
    output << student.toString();
    std::cout << "<<COMPLETE ostream_operator_overload" << std::endl;
    return output; //ostream object
}

// ==============================
// getters & setters

std::string Student::getName() const {
    std::cout << "get_name" << std::endl;
    return name;
}
int Student::getNumCourses() const {
    std::cout << "get_num_courses" << std::endl;
    return numCourses;
}
std::string Student::getCourse(const int index) const {
    std::cout << "BEGAN get_course["<< std::to_string(index) << "]" << std::endl;
    if (index < 0 || index >= numCourses) {
        throw std::out_of_range("Invalid course index");
    }
    std::cout << "COMPLETE get_course["<< std::to_string(index) << "]" << std::endl;
    return courseList[index];
}

void Student::setName(const std::string& newName) {
    std::cout << "set_name" << std::endl;
    this->name = newName;
}


