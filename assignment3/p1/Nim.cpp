//
// Created by kelse on 3/2/2024.
//

#include "Nim.h"

// Constructors for Nim.  No arguments for pile size will result in a random pile size between 10 and 100
Nim::Nim() : pile_size(Nim::randgen(10, 100)) {}
Nim::Nim(int size) : pile_size(size) {}

// Generate a random number
int Nim::randgen(int start, int stop){
    return rand() % (stop - start + 1) + start;
}
// Return the base 2 logarithm of a number
double Nim::log2(int x){
    return log(x) / log(2);
}
// Get input from a player from the command line
void Nim::player_move(std::string player_name){
    // Set a flag for valid input
    bool valid = false;
    std::ostringstream stream;
    int amount;
    while (!valid){
        // Get an amount from the user
        std::cout << player_name << ":" << std::endl << "How many to remove? Select integers between 1 and " << (int)pile_size / 2 << ":";
        std::cin >> amount;

        // If amount is not valid, loop back over
        // Currently, if the imput is not of type int, the buffer will not clear and an infinite loop will be triggered
        // Only input numeric types!
        if (amount < 1 || amount > this->pile_size / 2){
            stream << "Invalid selection. Select integers between 1 and " << (int)pile_size / 2 << std::endl;
        }
        else valid = true;
    }

    this->pile_size = this->pile_size - amount;
}
// A "Stupid" computer move. Removes a random amount from the pile greater than 1, but less than pile size / 2
void Nim::stupid_move(std::string player_name){
    int diff = this->pile_size - Nim::randgen(1, (int)this->pile_size / 2);
    this->pile_size = this->pile_size - diff;

    std::cout << player_name << ":" << std::endl << "(Stupid M) Computer removed:" << std::to_string(diff) << std::endl;
}
// A "Smart" computer move.  Removes an amount from the pile so that the resulting pile size will be
// a power of 2 minus 1 (3, 7, 15, 31, 63, etc.)
void Nim::smart_move(std::string player_name){
    // Get the base 2 logs of the pile and half the pile
    double log = Nim::log2(this->pile_size + 1);
    double log_half = Nim::log2(this->pile_size / 2 + 1);
    // Find the highest power of two within the pile
    int log_floor = floor(log);
    // Find the lowest power of two that is greater than half the pile size
    int log_half_ceil = ceil(log_half);

    // If the lowest power of two that is greater than half the pile size is greater than
    // the highest power of two within the pile, set the lowest power grtr than pile/2 is the same as the highest
    // power of 2 (this can happen because the lowest power grtr than pile/2
    // is found by using ceil.  This can give us numbers greater than the highest power within the whole pile)
    if (log_half_ceil > log_floor) log_half_ceil = log_floor;

    // If the pile + 1 is a power of 2, call the stupid move instead
    if (log - log_floor == 0){
        this->stupid_move(player_name);
        return;
    }

    // Find a power of two within pile greater than half the pile.
    int delta = Nim::randgen(log_half_ceil, log_floor);
    // Get the difference between the pile size and the new delta
    int diff = this->pile_size - (pow(2, delta) - 1);
    // Set the pile to the new delta
    this->pile_size = (pow(2, delta) - 1);

    std::cout << player_name << ":" << std::endl << "(Smart M) Computer removed:" << std::to_string(diff) << std::endl;
}
void Nim::play(int mode){
    std::map<int, std::string> modes {{0, "stupid"}, {1, "smart"}};
    std::cout << "Mode:" << modes[mode] << std::endl;

    // First player is chosen randomly
    int player = Nim::randgen(0,1);
    std::string player_name1 = "Player 1";
    std::string player_name2 = "Player 2";

    // While the pile size is greater than one
    while (this->pile_size > 1) {
        this->print_remaining();
        if (player) {
            player_move(player_name1);
        } else {
            if (mode) this->smart_move(player_name2);
            else this->stupid_move(player_name2);
        }

        player = !player;
        std::cout << std::endl;
    }
    this->print_remaining();
    std::cout << std::endl;
    if (player) std::cout << player_name2 << " Wins" << std::endl;
    else std::cout << player_name1 << " Wins" << std::endl;
}
void Nim::print_remaining(){
    std::ostringstream stream;
    stream << "Marbles remaining:" << this->pile_size << std::endl;
    std::cout << stream.str();
}