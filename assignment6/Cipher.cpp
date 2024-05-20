#include "Cipher.h"

Cipher::Cipher(){
    // Initialize the cipher map with every ascii character.  Set to 0
    for (uint8_t i = 0; i < 255; i++){
        this->cipher[i] = 0;
    }
}
void Cipher::readFile(std::string path){
    std::ifstream file;
    file.open(path);

    char c;
    while (file){
        c = file.get();
        this->total++;
        this->cipher[c]++;
    }

    double per = 100.0 / this->total;
    for (uint8_t i = 0; i < 255; i++){
        if (this->cipher[i] == 0){
            this->cipher.erase(i);
        }
        else{
            this->cipher[i] = this->cipher[i] * per;
        }
    }
}
void Cipher::print(){
    for (uint8_t i = 0; i < 255; i++){
        if (this->cipher[i] != 0){
            std::cout << i << ":" << this->cipher[i] << std::endl;
        }
    }
}