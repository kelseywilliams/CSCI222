//
// Created by kelse on 3/3/2024.
//

#include "BarcodeManager.h"

// Prompt user for a postal code and prints the corresponding barcode
void BarcodeManager::newBarcode(){
    std::string zip;
    bool valid = false;

    // Prompt for a postal code until a valid entry is given
    while(!valid){
        std::cout << "Enter a postal code:";
        std::cin >> zip;

        valid = this->createBarcode(zip);
    }
    this->print();
}
// Create new barcode
int BarcodeManager::createBarcode(std::string input){
        int zip = std::stoi(input);             // Convert zip code from string to integer
        int check, digit;
        int temp = 0;
        if (zip > 99999 || zip < 1000) return 0;    // If zip code is not valid, return 0

        // Loop through the number one digit at a time
        for (int i = 4; i > -1; i--){
            digit = (int)floor(zip / pow(10, i)) % 10;   // Get the current digit
            temp += digit;
            // Get the code for the specified index and push it to the barcode
            this->barcode.push_back(this->code[digit]);
        }
        // Get the check digit and push its digit's code onto the barcode
        check = floor(temp / 10);
        this->barcode.push_back(this->code[check]);

        return 1;
}
void BarcodeManager::print(){
    std::ostringstream stream;

    // Bookend the barcode with |
    stream << "|";
    // For each digit in the barcode, print out | for 1s and : for 0s.
    for (int i = 0; i < this->barcode.size(); i++){
        for (int j = 0; j < this->barcode[i].size(); j++){
            if (this->barcode[i][j]) stream << "|";
            else stream << ":";
        }
    }
    stream << "|" << std::endl;

    std::cout << stream.str();
}