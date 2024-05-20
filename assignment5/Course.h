#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <cstdint>
#include "Student.h"

#ifndef COURSE_H
#define COURSE_H

class Student;  // This is forward declaration.  Pay attention or no inter referential classes.

class Course {
    std::string name;
    std::vector<Student*> students;
public:
    Course(std::string name);
    void print_student(Student* s);
    void print_course(Course* c);
    void enroll(Student* s, Course* c);
    void printByGrade();
    std::string getName();
};

#endif
