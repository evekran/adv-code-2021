#include <iostream>
#include <fstream>
#include <numeric>

void xxx_pt_one(std::ifstream &input) {
    std::string line;

    if (input.is_open()) {
        while ( getline (input,line) )
        {
            // Solution
        }
    } else {
        std::cout << "File not found";
    }
}

void xxx_pt_two(std::ifstream &input) {
    std::string line;

    if (input.is_open()) {
        while ( getline (input,line) )
        {
           // Solution
        }
    } else {
        std::cout << "File not found";
    }
}

int xxx() {
    std::cout << "Day 3: XXX" << std::endl;
    std::ifstream input;
    input.open("../inputs/03_xxx.txt");

    xxx_pt_one(input);
    input.clear();
    input.seekg(0);
    xxx_pt_two(input);

    input.close();
    return 0;
}