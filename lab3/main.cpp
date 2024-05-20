#include "read_input.h"
#include "Matrix.h"
#define testno 8
int main(int argc, char** argv) {
    std::vector<Matrix<double>> matrices;
    std::vector<Matrix<double>> test_cases(testno);

    // Read matrices
    matrices = read_input(R"(C:\Users\kelse\projects\CSCI222\lab3\input.txt)");

    // Test addition
    test_cases[0] = matrices[0] + matrices[1];
    // Test subtraction
    test_cases[1] = matrices[0] - matrices[1];
    // Test multiplication
    test_cases[2] = matrices[3] * matrices[4];
    // Test incrementation
    test_cases[3] = ++matrices[2];
    // Test decrementation
    test_cases[4] = --matrices[1];
    // Test transposition
    test_cases[5] = ~matrices[2];
    // Test exponentials
    test_cases[6] = matrices[4]^4;
    // Increment matrix of decimal numbers
    test_cases[7] = ++matrices[5];

    // Print test cases
    for (int i = 0; i < testno; i++)
        std::cout << test_cases[i] << std::endl;

    return 0;
}