#include <iostream>
#include <string>
#include <sstream>
#include <array>

// Create months array
std::array<std::string, 12> months = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

// Returns Easter, given a year as a string
std::string find_easter(std::string year);

int main(){
    std::string input;
    std::string output;

    std::cout << "Enter a year: ";

    getline(std::cin, input);

    output = find_easter(input);

    std::cout << output << std::endl;
}

std::string find_easter(std::string year){
    // Declare string stream and strings
    std::ostringstream stream;
    std::string month;
    std::string day;
    std::string output;

    // Convert string to integer
    int y = std::stoi(year);

    // +*+ Begin the magic *+*
    int a = y % 19;
    int b = y / 100;
    int c = y % 100;
    int d = b / 4;
    int e = b % 4;
    int g = (8 * b + 13) / 30;
    int h = (19 * a + b - d - g + 15) % 30;
    int j = c / 4;
    int k = c % 4;
    int m = (a + 11 * h) / 319;
    int r = (2 * e + 2 * j - k - h + m + 32) % 7;
    int n = (h - m + r + 90) / 25;
    int p =  (h - m + r + n + 19) % 32;

    // Get month from months array and convert day to string
    month = months[n - 1];
    day = std::to_string(p);
    
    // Build output stream
    stream << "In " << year << ", Easter Sunday falls on " << month << " " << day << ".";

    // Convert output stream to string
    output = stream.str();

    return output;
}