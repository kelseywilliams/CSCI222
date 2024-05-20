#include <time.h>
#include <random>
#include "UniqueWords.h"
#include "Student.h"
#include "Course.h"

// Worker functions for the main function
double randgen(int start, int stop);
void setScores(double* scores);

int main(){
    srand(time(0));
    // P7.7
    std::cout << "P7.7" << std::endl << std::endl;
    UniqueWords uw;
    uw.readFile(R"(C:\Users\kelse\projects\CSCI222\assignment5\input.txt)");
    //uw.printWords();
    uw.printAddrs();

    // P7.8, P7.9 and p7.10
    std::cout << std::endl << "P7.8-7.10" << std::endl << std::endl;

    // Create course
    Course csci("CSCI 222");
    Course eng("ENGL 100");
    Course math("MATH 140");
    // create an array to hold scores
    double scores[NUM_SCORES];

    // Create students and generate some random scores
    setScores(scores);
    Student s1("Smith", "John", scores);
    setScores(scores);
    Student s2("Smith", "Jane", scores);
    setScores(scores);
    Student s3("Trump", "Donald", scores);
    setScores(scores);
    Student s4("Biden", "Joseph", scores);
    setScores(scores);
    Student s5("Obama", "Barrack", scores);

    // Enroll the students in classes
    csci.enroll(&s1, &csci);
    csci.enroll(&s2, &csci);
    csci.enroll(&s3, &csci);
    csci.enroll(&s3, &eng);
    csci.enroll(&s3, &math);
    csci.enroll(&s4, &csci);
    csci.enroll(&s5, &csci);

    // Print all students in the course by grade
    csci.printByGrade();
    std::cout << std::endl;
    // Print all students as were entered into the course
    csci.print_course(&csci);
    std::cout << std::endl;
    // Print Donald Tumps name, grade and classes
    csci.print_student(&s3);
}
double randgen(int start, int stop){
    return rand() % (stop - start + 1) + start;
}
void setScores(double* scores){
    for (int i = 0; i < NUM_SCORES; i++){
        scores[i] = randgen(70, 100);
    }
}