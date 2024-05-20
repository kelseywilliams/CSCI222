#include <iostream>
#include <string>
#include <sstream>
#include <array>

double total_cost();

int main(){
    double output = total_cost();
    std::cout << output << std::endl;
    return 0;
} 

double total_cost(){
    std::string scost, smiles, sgas, sresale;
    double cost, gas, resale, output;
    int miles;

    // Get total cost of a new car
    std::cout << "Enter the cost the car: ";
    getline(std::cin, scost);

    std::cout << "Enter the miles driven per year: ";
    getline(std::cin, smiles);

    std::cout << "Enter the estimated gas price: ";
    getline(std::cin, sgas);

    std::cout << "Enter the estimated resale value after 5 years: ";
    getline(std::cin, sresale);

    // Declare string stream and strings
    cost = std::stod(scost);
    gas = std::stod(sgas);
    miles = std::stoi(smiles);
    resale = std::stod(sresale);

    output = ((((double)miles * 5) / 55) * gas + cost) - resale;
    // Get month from months array and convert day to string

    return output;
}