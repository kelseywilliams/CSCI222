#include "Student.h"
#include "Course.h"
// Empty Constructor.  Prompt functions will be needed to enter student and scores
Student::Student(){
    for(int i = 0; i < NUM_SCORES; i++){
        this->scores[i] = 0;
    }
    this->avg = 0;
}
// Initialize a student using the constructer without prompts
Student::Student(const std::string lname, const std::string fname, double *scores){
    this->lname = lname;
    this->fname = fname;
    double total;
    for (int i = 0; i < NUM_SCORES; i++){
        total += scores[i];
        this->scores[i] = scores[i];
    }
    this->avg = total / NUM_SCORES;
    this->grade = this->calcGrade(this->avg);
}
// Enter student via the command line interface
void Student::promptStudent(){
    std::ostringstream stream;

    std::cout << "Enter Student in format `<first name> <last name>`" << std::endl;
    std::cin >> this->fname;
    std::cin >> this->lname;
}
// Enter grades via the command line interface
void Student::promptGrades(){
    int total = 0;
    std::cout << "Enter 10 scores for the Student:" << std::endl;
    for (int i = 0; i < NUM_SCORES; i++){
        std::cin >> this->scores[i];
        total += this->scores[i];
    }
    this->avg = total / NUM_SCORES;
    grade = this->calcGrade(total / NUM_SCORES);
}
// Return letter grade as string from grade avg of type double
std::string Student::calcGrade(double s){
    if (s >= 90) return "A";
    if (s >= 80) return "B";
    if (s >= 70) return "C";
    if (s >= 60) return "D";
    if (s >= 50) return "E";
}
// Access function to append to courses member variable
void Student::addCourse(Course* c){
    this->courses.push_back(c);
}
// Split string based on delimiter
std::vector<std::string> Student::split(std::string delim, std::string str) {
    std::vector<std::string> result(0);
    int pos_start = 0;
    int pos_end, delim_len = delim.length();
    std::string token;

    while ((pos_end = str.find(delim, pos_start)) != std::string::npos) {
        token = str.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        result.push_back(token);
    }
    result.push_back(str.substr(pos_start));
    return result;
}
// Return member variable courses
std::vector<Course*> Student::getCourses(){
    return this->courses;
}
// Print all course names that student is enrolled in
void Student::print_courses(){
    for (Course* course: this->courses){
        std::cout << course->getName() << std::endl;
    }
}
// Print student last name, first name, and letter grade
void Student::print(){
    std::cout << this->lname << ", " << this->fname << ": " << this->getAvg() << std::endl;
}
// Return the grade average
double Student::getAvg(){
    return this->avg;
}