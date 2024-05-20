#include <iostream>
#include <vector>
#include <unistd.h>

class GameOfLife {
private:
    int rows;
    int cols;
    std::vector<std::vector<bool>> grid;

public:
    GameOfLife(int rows, int cols) : rows(rows), cols(cols), grid(rows, std::vector<bool>(cols, false)) {}

    void randomize() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                grid[i][j] = rand() % 2 == 0;
            }
        }
    }

    void print() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << (grid[i][j] ? "*" : ".");
            }
            std::cout << std::endl;
        }
    }

    int countNeighbors(int x, int y) {
        int count = 0;
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (i == 0 && j == 0) continue;
                int newX = x + i;
                int newY = y + j;
                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY]) {
                    ++count;
                }
            }
        }
        return count;
    }

    void update() {
        std::vector<std::vector<bool>> newGrid = grid;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int neighbors = countNeighbors(i, j);
                if (grid[i][j]) {
                    if (neighbors < 2 || neighbors > 3) {
                        newGrid[i][j] = false;
                    }
                } else {
                    if (neighbors == 3) {
                        newGrid[i][j] = true;
                    }
                }
            }
        }
        grid = newGrid;
    }

    void run(int generations, int delay) {
        for (int i = 0; i < generations; ++i) {
            std::cout << std::endl;
            print();
            update();
            usleep(delay * 1000);
        }
    }
};

int main() {
    int rows = 20;
    int cols = 40;
    int generations = 100;
    int delay = 100;

    GameOfLife game(rows, cols);
    game.randomize();
    game.run(generations, delay);

    return 0;
}
