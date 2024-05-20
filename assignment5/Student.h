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

#ifndef STUDENTS_H
#define STUDENTS_H
#define NUM_SCORES 10

class Course; // Forward declaration

class Student {
    std::string fname;
    std::string lname;
    std::string grade;
    double avg = 0;
    double scores[NUM_SCORES];
    std::vector<Course*> courses;

public:
    Student();
    Student(std::string lname, std::string fname, double *scores);
    static std::vector<std::string> split(std::string delim, std::string str);

    // Get user student input from the command line
    void promptStudent();
    void promptGrades();

    // Worker functions
    static std::string calcGrade(double s);
    void addCourse(Course* c);
    double getAvg();
    std::vector<Course*> getCourses();

    // Print functions
    void print_courses();
    void print();
};


#endif
