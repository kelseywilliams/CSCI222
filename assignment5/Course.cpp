#include <Course.h>
// Constructor for class course
Course::Course(std::string name){
    this->name = name;
}
std::string Course::getName(){
    return this->name;
}
// Print student name and grade followed by all the courses that student is enrolled in
void Course::print_student(Student* s){
    s->print();
    for (Course* course: s->getCourses()){
        std::cout << course->getName() << std::endl;
    }
}
// Print the course name followed by all students enrolled in the class
void Course::print_course(Course* c){
    std::cout << c->name << std::endl;
    for (Student* student: c->students){
        student->print();
    }
}
// Enroll a student in a course.  TODO Could be static
void Course::enroll(Student* s, Course* c){
    c->students.push_back(s);
    s->addCourse(c);
}
// Print students in course by grade
void Course::printByGrade(){
    std::vector<Student*> temp = this->students;

    // Go through all the temp vector of students
    for (int i = 0; i < temp.size(); i++){
        // At every index, check if that value is less than any of the previous values
        auto it = std::find_if(temp.begin(), temp.begin() + i, [temp, i](Student * s){
            if (temp[i]->getAvg() < s->getAvg())
                return true;
            return false;
        });
        // If temp[i] is less than a previous value, insert temp[i] before that value and erase temp[i]
        if (it != temp.begin() + i) {
            temp.insert(it, temp[i]);
            temp.erase(temp.begin() + i + 1);
        }
    }

    std::cout << this->getName() << " By Grade" << std::endl;
    for (Student * student: temp){
        student->print();
    }
}
