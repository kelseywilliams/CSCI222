//
// Created by kelse on 3/7/2024.
//

#include "Simulator.h"

#define ROWS 10
#define COLUMNS 10

Simulator::Simulator(int gens) {
    this->gens = gens;
}

// Populate board
void Simulator::populate(){
    this->state.clear();
    // Set size of outter vector
    this->state.resize(ROWS);
    // Loop through columns and rows and randomly place a 1 or 0 with a 1/20 chance of adding a 1
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLUMNS; j++){
            if (!Simulator::randgen(0,15)){
                this->state[i].push_back(1);
            }
            else this->state[i].push_back(0);
        }
    }
}
int Simulator::randgen(int start, int stop){
    return rand() % (stop - start + 1) + start;
}
std::string Simulator::outChar(int x){
    if (x) return "o";
    else return " ";
}
// Check if the state instance variable contains only 0's.
// If true, everything has died.  Else there is still life
bool Simulator::checkPulse(const std::vector<std::vector<int>> vs) {
    for(const auto& v : vs) {
        for(auto x : v) {
            if(x != 0) {
                return true;
            }
        }
    }
    return false;
}
// Generate new state
int Simulator::newState(){
    // Create buff to store altered version of state
    std::vector<std::vector<int>> buff;
    buff.resize(ROWS);
    int n;
    // Loop through each cell in the vector of vectors
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLUMNS; j++){
            n = this->countNeighbor(i, j);
            // If there are 3 neighbors, a new cell is born
            if (n == 3) buff[i].push_back(1);
            // If there are more than 3 neighbors or less than 3, the cell dies.
            if (n >= 4 || n <= 1) buff[i].push_back(0);
            // Otherwise set the current cell to current value
            else buff[i].push_back(this->state[i][j]);
        }
    }
    // Check that everything hasn't died.
    if(!Simulator::checkPulse(buff)){
        return 1;
    }

    // Set the state to the buffer contents
    this->state = buff;
    return 0;
}
// Count how many cells around a current cell are occupied.
int Simulator::countNeighbor(int x, int y){
    // Set x and y to search for
    int search_x, search_y;
    int count = 0;

    // Add -1, 0, and 1 to x and y and if the results are not greater than 0 or max index
    for (int i = -1; i < 2; i++){
        if (x + i < 0 || x + i >= ROWS) continue;
        for (int j = -1; j < 2; j++){
            if (y + j < 0 || y + j >= COLUMNS) continue;

            search_x = x + i;
            search_y = y + j;

            // If the two search terms equal the input terms, continue
            if (search_x == x && search_y == y) continue;
            // Increment count if the cell is found to be occupied
            if (this->state[search_x][search_y]) count++;
            // If the count equals 4, return count even though there are a maximum of 7 neighbor
            // Saves big O.
            if (count == 4) return count;
        }
    }
    return count;
}
// Run simulation
void Simulator::simulate(){
    int result;
    // Populate board
    this->populate();
    for (int i = 0; i < this->gens; i++){
        // Set new state and capture result
        result = this->newState();
        // If everything has died, restart if it was the first round
        // Otherwise alert the user to the fact that everything has died.
        if (result){
            if (i < 2){
                this->populate();
                i = 0;
                continue;
            }
            std::cerr << "Everything died.  Exiting program..." << std::endl;
            exit(1);
        }
        this->printBoard(i);
    }
}
// Print how neighbors each cell has in the cell
void Simulator::printNeighbors(){
    std::ostringstream stream;
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLUMNS; j++){
            stream << std::to_string(this->countNeighbor(i, j)) << " ";
        }
        stream << std::endl;
    }
    stream << std::endl;
    std::cout << stream.str();
}
// Print the current state of the board
void Simulator::printBoard(int gen){
    //std::cout << "\x1b[d";
    std::ostringstream stream;
    stream << std::to_string(gen) << std::endl;
    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLUMNS; j++){
            stream << Simulator::outChar(this->state[i][j]) << " ";
        }
        stream << std::endl;
    }
    stream << std::endl;
    stream << "============================" << std::endl;
    std::cout << stream.str();
}