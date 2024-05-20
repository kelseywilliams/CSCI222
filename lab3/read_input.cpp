#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include "Matrix.h"

std::vector<Matrix<double>> read_input(std::string path){
    std::string PATH = path;
    std::ifstream file;
    file.open(PATH);

    std::vector<std::vector<double>> outer;
    std::vector<double> inner;
    std::vector<Matrix<double>> matrices;

    char c;
    bool aflag = false;
    std::ostringstream buffer;
    outer.resize(0);


    if (file.is_open()){
        while(file){
            c = file.get();
            if (c == '[') {
                aflag = true;
                continue;
            }
            if (aflag){
                if (c == ' ' || c == ']' || c == '\n'){
                    std::string output = buffer.str();
                    //printf("%f", std::stod(output));
                    inner.push_back(std::stod(output));
                    buffer.str("");
                    buffer.clear();
                    if (c == ' ') continue;
                    if (c == ']') {
                        aflag = false;

                        outer.push_back(inner);
                        Matrix<double> m(outer);
                        matrices.push_back(m);
                        inner.clear();
                        outer.clear();
                    }
                    else if (c == '\n'){
                        outer.push_back(inner);
                        inner.clear();
                    }
                }
                else {
                    buffer << c;
                }
            }
        }
    }
    return matrices;
}