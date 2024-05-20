#include "Cipher.h"
#include "Playfair.h"

// Cool! Save for later date!
// Get size of static array
//template<typename T, unsigned S>
//inline unsigned arraysize(const T (&v)[S]){
//    return S;
//}

int main(){
    Cipher c;
    c.readFile(R"(C:/Users/kelse/projects/CSCI222/assignment6/input.txt)");
    c.print();

    std::string key = "playfair";
    Playfair p(key);
    p.inputFile(R"(C:/Users/kelse/projects/CSCI222/assignment6/input.txt)");
    p.printEncrypted();
    p.printDecrypted();
    return 0;
}