#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "Hello, my name is Hal!\nWhat would you like me to do?\n";
    string user_input;
    getline(cin, user_input);
    cout << "I am sorry, I cannot do that.\n";
    return 0;
}