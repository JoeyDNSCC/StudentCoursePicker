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
    [[nodiscard]] std::string toString() const;
    void flunkOut();
    friend std::ostream &operator<<(std::ostream &output, Student &student);

    // getters
    [[nodiscard]] std::string getName() const;
    [[nodiscard]] int getNumCourses() const;
    [[nodiscard]] std::string getCourse(int index) const;
    void setName(const std::string& newName);
};


#endif //COURSES_STUDENT_H
