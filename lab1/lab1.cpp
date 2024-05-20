#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <string>

#define S_EXP_L 6 // Define length of singular exception array
#define P_EXP_L 2   // Define length of plural exception array
#define V_L 5  // Define length of vowel array
// Define singular excetpions array
const char* s_exp[S_EXP_L] = { "belize", "cambodge", "mexique", "mazambique", "zaire", "zimbabwe" };
// Define plural exceptions array
const char* p_exp[P_EXP_L] = { "Etats-Unis", "Pays-Bas" };
// Define vowels
const char* v = "aeiou";
/* Tests input for exceptions to french article rules for countries
    @params input of type std::string
    @returns the exception concatenated with its appropriate article
 */
std::string test_exceptions(std::string input);
/* Tests gender of input and prepends appropriate artcile
    @params input of type std::string
    @returns input string concatenated with its appropriate article
 */
std::string test_gender(std::string input);

int main() {
    int i = 0;
    do
    {
        std::cout << "We may C" << std::endl;
        i++;
        if (i % 4 == 0)
        {
            i = 11;
        }
    }
    while (i <= 10);

    //are input
    std::string input;

    // Declare output
    std::string output;

    // Scan indefinitely for french countries
    while (1) {
        // Prompt user imput
        std::cout << ">";

        // Get input from stdin
        getline(std::cin, input);

        // Tests input for exceptions
        // If exceptions apply, print exception and jump back to input collection
        output = test_exceptions(input);
        if (output.length() > 0) {
            std::cout << output << std::endl;
            continue;
        }

        // Determine if word is masculine or feminine and apply the proper article
        output = test_gender(input);

        // print output to stdout
        std::cout << output << std::endl;
    }
}

std::string test_exceptions(std::string input) {
    std::string output = ""; // Declare output string

    // Store lowercase copy of input to compare against lowercase records
    std::string input_l = input;
    std::transform(input_l.begin(), input_l.end(), input_l.begin(), ::tolower);

    // Check if input is in exception list 
    for (int i = 0; i < S_EXP_L; i++) {
        // If input is found in singular exceptions list, prepend appropriate article and return
        if (input_l == s_exp[i]) {
            output = "le " + input;
            return output;
        }
    }
    // Check if input is in plural exceptions list
    for (int i = 0; i < P_EXP_L; i++) {
        // If input is found in plural exceptions list, prepend appropriate article and return
        if (input == p_exp[i]) {
            output = "les " + input;
            return output;
        }
    }
    // Check if input starts with vowel
    for (int i = 0; i < V_L; i++) {
        // If input is found in vowels list, prepend appropriate article and return
        if (input_l[0] == v[i]) {
            output = "l'" + input;
            return output;
        }
    }
    // Return empty string if input does not match any exceptions
    return output;
}

std::string test_gender(std::string input) {
    std::string output = ""; // Declare output string

    // Store lowercase copy of input to compare against lowercase records
    std::string input_l = input;
    std::transform(input_l.begin(), input_l.end(), input_l.begin(), ::tolower);
    
    // If input ends in e, it is feminine.  Otherwise it is male.
    // Prepends appropriate article and returns output
    if (input.back() == 'e')
        output = "la " + input;
    else
        output = "le " + input;
    return output;
}