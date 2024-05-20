#include "Playfair.h"

Playfair::Playfair(std::string key){
    // Convert key word into a char array and remove duplicate letters
    std::vector<char> alpha;
    std::vector<char> word;
    std::vector<char> key_chars;
    // Fill the alpha vector with the alphabet excluding j
    for (char i = 97; i < 123; i++){
        if (i == 106) continue;
        else alpha.push_back(i);
    }
    // Convert string to char vector for easier handling
    for (char i : key) word.push_back(i);

    // Go through the key word letter by letter
    for (int i = 0; i < word.size(); i++){
        // Check the rest of the vector for any duplicate characters later
        auto it = std::find_if(word.begin() + i + 1, word.end(), [word, i](char c){
            if(c == word[i]) return true;
            return false;
        });
        // If duplicate characters are found later, remove them using the iterator returned above
        if (it != word.end()){
            word.erase(it);
        }
        // Remove the current character from the alphabet vector
        it = std::find(alpha.begin(), alpha.end(), word[i]);
        if (it != alpha.end()){
            alpha.erase(it);
        }
        // Push the current character onto the final key word character vector
        key_chars.push_back(word[i]);
    }
    // Insert the rest of the alphabet into the key chars
    for (char c: alpha) key_chars.push_back(c);

    this->key.resize(5);
    int count = 0;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            this->key[i].push_back(key_chars[count]);
            count++;
        }
    }
}

void Playfair::inputFile(std::string path){
    std::ifstream file;
    file.open(path);

    std::string output;
    std::ostringstream buff;
    char c;
    while (file){
        c = file.get();
        // Manipulate ascii values directly and work with type char for ease
        // If the character is uppercase, add 32 to make it lowercase
        if (c >= 65 && c <= 90){
            c = c + 32;
        }
        if (c >= 97 && c <= 122){
            buff << c;
        }
        else{
            if (buff.str().size() == 0) continue;
            output = this->encrypt(buff.str());
            this->encrypted.push_back(output);
            buff.str("");
            buff.clear();
        }
    }
    // Decrypt all words and place in decrypted
    for (std::string word: this->encrypted) this->decrypted.push_back(this->decrypt(word));
}
std::string Playfair::encrypt(std::string data){
    std::vector<char> word;
    std::ostringstream buff;
    for (char c: data) word.push_back(c);

    // Process word to ensure even length and insert dummy characters where necessary
    int i = 0;
    while (i < word.size() - 1){
        if (word[i + 1] == word[i]){
            word.insert(word.begin() + i + 1, BUFF_CHAR);
        }
        i++;
    }
    if (word.size() % 2 != 0) word.push_back(END_CHAR);

    i = 0;
    while (i < word.size() - 1){
        int row, row2, col, col2;
        std::tuple<int, int> coords;
        coords = getCoords(word[i]);
        row = std::get<0>(coords);
        col = std::get<1>(coords);
        coords = getCoords(word[i + 1]);
        row2 = std::get<0>(coords);
        col2 = std::get<1>(coords);

        if (row == row2) {
            (col == 4) ? col = 0 : col++;
            (col2 == 4) ? col2 = 0 : col2++;
        } else if (col == col2) {
            (row == 4) ? row = 0 : row++;
            (row2 == 4) ? row2 = 0 : row2++;
        } else {
            int temp = col;
            col = col2;
            col2 = temp;
        }
        buff << this->key[row][col] << this->key[row2][col2];
        i = i + 2;
    }

    return buff.str();
}
std::string Playfair::decrypt(std::string data){
    std::vector<char> word;
    std::ostringstream buff;
    for (char c: data) word.push_back(c);

    int i = 0;
    while (i < word.size() - 1){
        int row, row2, col, col2;
        std::tuple<int, int> coords;
        coords = getCoords(word[i]);
        row = std::get<0>(coords);
        col = std::get<1>(coords);

        coords = getCoords(word[i + 1]);
        row2 = std::get<0>(coords);
        col2 = std::get<1>(coords);

        if (row == row2) {
            (col == 0) ? col = 4 : col--;
            (col2 == 0) ? col2 = 4 : col2--;
        } else if (col == col2) {
            (row == 0) ? row = 4 : row--;
            (row2 == 0) ? row2 = 4 : row2--;
        } else {
            int temp = col;
            col = col2;
            col2 = temp;
        }
        buff << this->key[row][col] << this->key[row2][col2];
        i = i + 2;
    }
    return buff.str();
}
std::tuple<int, int> Playfair::getCoords(char c){
    for (int i = 0; i < this->key.size(); i++){
        for (int j = 0; j < this->key[0].size(); j++){
            if (this->key[i][j] == c){
                return std::make_tuple(i, j);
            }
        }
    }
}
void Playfair::printEncrypted(){
    for (std::string word: this->encrypted) {
        std::cout << word << " ";
    }
    std::cout << std::endl;
}

void Playfair::printDecrypted(){
    for (std::string word: this->decrypted) {
        std::cout << word << " ";
    }
    std::cout << std::endl;
}