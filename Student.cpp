#include "Student.h"

#include <iostream>
#include <string>
#include <strstream>
#include <utility>


// default constructor
Student::Student()
    :numCourses(0), courseList(new std::string[numCourses]) {

    std::cout << "defaultConstructor" << std::endl;
}

// string constructor
Student::Student(std::string name)
    :name(std::move(name)), numCourses(0), courseList(new std::string[numCourses]) {

    std::cout << "string_constructor" << std::endl;
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
    std::cout << "BEGAN assignment_operator_overload" << std::endl;

    // in case assigned to itself
    if (this == &rightObj) return *this;

    this->name = rightObj.name;

    // allocate memory for new array
    auto* temp = new std::string[rightObj.numCourses];

    // copy courses
    for (int i = 0; i < rightObj.numCourses; i++) {
        temp[i] = rightObj.courseList[i];
    }

    delete[] courseList; // delete old array

    // assign new array & size to this object
    courseList = temp;
    numCourses = rightObj.numCourses;

    std::cout << "COMPLETE assignment_operator_overload" << std::endl;

    return *this; // stu1 = stu2 = stu3 = ...
}


// destructor
Student::~Student() {
    std::cout << "BEGAN destructor " << this->name << std::endl;

    // not sure if erase() is necessary
    // this->name.erase();
    // for (int i = numCourses - 1; i >= 0; i--) {
    //     this->courseList[i].erase();
    // }

    // if (courseList != nullptr) // ask abt redundant null check
    delete[] this->courseList;

    std::cout << "COMPLETE destructor _" << std::endl;
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
    std::cout << "BEGAN toString " << this->name << std::endl;
    try {

        // instance str
        std::string output;

        // wasting time on pretty output
        if (this->numCourses == 0) {
            output = "\n" + this->name + " is not enrolled in any courses";
        } else {
            output.append("\n" + this->name + " is in " + std::to_string(this->numCourses) +" course(s):\n");

            if (this->numCourses == 1) {
                output.append(this->courseList[0]);
            } else if (this->numCourses == 2) {
                output.append(this->courseList[0] + " and " + this->courseList[1]);
            } else {
                for (int i = 0; i < this->numCourses - 1; i++) {
                    output.append(this->courseList[i] + ", ");
                }
                output.append("and " + this->courseList[this->numCourses - 1]);
            }
        }
        output.append("\n");
        std::cout << "COMPLETE toString" << this->name << std::endl;
        return output;

    // DOESNT catch out of range error :(
    } catch (std::exception& e) {
        std::cout << "ERROR toString " << std::endl;
        return e.what();
    }
    return "dude what happened";
}


// overloaded << operator
std::ostream& operator<<(std::ostream &output, Student &student) {
    std::cout << "BEGAN ostream_operator_overload" << std::endl;

    output << student.toString() << std::endl;

    std::cout << "COMPLETE ostream_operator_overload";
    return output; //ostream object
}


// drop all courses from student
void Student::flunkOut() {
    std::cout << "BEGAN flunk_out" << std::endl;

    this->numCourses = 0;
    delete[] this->courseList;
    // empty list instead of null
    courseList = new std::string[numCourses];

    std::cout << "COMPLETE flunk_out" << std::endl;
}


// ==============================
// getters & setters


std::string Student::getName() const {
    //std::cout << "get_name" << std::endl;
    return name;
}
int Student::getNumCourses() const {
    //std::cout << "get_num_courses" << std::endl;
    return numCourses;
}
std::string Student::getCourse(const int index) const {
    //std::cout << "BEGAN get_course["<< std::to_string(index) << "]" << std::endl;
    if (index < 0 || index >= numCourses) {
        throw std::out_of_range("Invalid course index");
    }
    //std::cout << "COMPLETE get_course["<< std::to_string(index) << "]" << std::endl;
    return courseList[index];
}

void Student::setName(const std::string& newName) {
    std::cout << "set_name: " << this->name << " to " << newName << std::endl;
    this->name = newName;
}


