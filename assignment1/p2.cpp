#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "Hello, my name is Hal!\nWhat is your name?\n";
    string user_name;
    getline(cin, user_name);
    cout << "Hello, " << user_name << ", I am glad to meet you!";
    return 0;
}