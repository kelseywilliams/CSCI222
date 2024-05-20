#include "UniqueWords.h"
void UniqueWords::readFile(std::string path){
    std::ifstream file;
    file.open(path);

    std::ostringstream buffer;
    std::vector<char*> temp_words;
    int counter = 0;
    int counter2 = 0;
    char* temp;
    char c;
    while (file) {
        // Get each character from the file
        c = file.get();
        // If the character is not part of a word, continue the loop
        if (c == '\n' || c == ',' || c == '.' || c == -1) continue;
        // If the character is a space, then a word has been found
        if (c == ' ') {
            // Allocate memory for the new word
            temp = (char*) malloc(buffer.str().size());
            // Copy the contents of the buffer into temp
            strcpy(temp, buffer.str().c_str());

            // | this is the type of auto == on the next line.  This comment left for educational purposes
            // v
            //std::vector<char*>::iterator it = std::find(temp_words.begin(), temp_words.end(), temp);

            // Find if temp is in temp_words
            auto it = std::find_if(temp_words.begin(), temp_words.end(), [temp](char* str){
                // If a strcmp of the two char pointers returns 0, the str == temp
                return !strcmp(str, temp);
            });
            // If temp is in temp_words, append the address of the first instance of the word
            // else append temp
            if (it == temp_words.end()){
                    counter += buffer.str().size();
            }
            counter2 += buffer.str().size();
            temp_words.insert(temp_words.end(), (it != temp_words.end()) ? *it : temp);
            // Clear the buffer
            buffer.str("");
        }
        else {
            buffer << c;
        }
    }
    // Empty the last element from the buffer
    temp = (char*) malloc(buffer.str().size());
    strcpy(temp, buffer.str().c_str());
    temp_words.push_back(temp);

    // Print total of number bytes and saved with this strategy
    // Number of bytes will be number of characters read in total from the file minus
    // the number of characters actually given a new address.
    std::cout << counter * 8 << " bytes used" << std::endl << 8 * (counter2 - counter) << " bytes saved" << std::endl;
    this->words = temp_words;
}

void UniqueWords::printWords(){
    for (char* word: this->words){
        std::cout << word << std::endl;
    }
}

void UniqueWords::printAddrs(){
    for (int i = 0; i < words.size(); i++){
        std::cout << words[i] << ":" << (void *) words[i] << std::endl;
    }
}