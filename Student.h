//
// Created by wolph on 10/22/2026.
//

#ifndef COURSES_STUDENT_H
#define COURSES_STUDENT_H
#include <string>


class Student {
    std::string name;
    int numCourses;
    std::string* courseList;

    public:
    // requested in assignment doc
    Student();
    // IDE recommended "explicit"
    explicit Student(std::string name);
    Student(const Student& student);
    Student& operator=(const Student &rightObj);
    ~Student();
    void add(const std::string& course);
    //IDE recommended [[nodiscard]] and const
    [[nodiscard]] std::string toString() const;
    friend std::ostream &operator<<(std::ostream &output, Student &student);

    // getters & setters
    std::string getName();
    int getNumCourses();
    std::string getCourseList();
    void setName(std::string name);
    void setNumCourses(int numCourses);
    void setCourseList(std::string* courseList);

};


#endif //COURSES_STUDENT_H
