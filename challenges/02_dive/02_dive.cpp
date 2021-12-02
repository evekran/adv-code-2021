#include <iostream>
#include <fstream>
#include <string>
#include <numeric>

void dive_pt_one(std::ifstream &input) {
    std::string command;

    int result ;
    int x = 0, y = 0;

    if (input.is_open()) {
        while ( getline (input,command) )
        {
            std::string delimiter = " ";
            std::string instruction = command.substr(0, command.find(delimiter));
            std::string value = command.erase(0, command.find(delimiter) + delimiter.length());

            if (instruction == "forward") {
                x += std::stoi(value);
            } else if (instruction == "up") {
                y -= std::stoi(value);
            } else if (instruction == "down") {
                y += std::stoi(value);
            } else {
                std::cout << "Unknown command";
            }
        }
    } else {
        std::cout << "File not found";
    }

    result = x * y;
    std::cout << "Horizontal position: " << x << std::endl;
    std::cout << "Depth: " << y << std::endl;
    std::cout << "Output: " << result << std::endl;
}

void dive_pt_two(std::ifstream &input) {
    std::string command;

    int result ;
    int x = 0, y = 0, aim = 0;

    if (input.is_open()) {
        while ( getline (input,command) )
        {
            std::string delimiter = " ";
            std::string instruction = command.substr(0, command.find(delimiter));
            std::string value = command.erase(0, command.find(delimiter) + delimiter.length());

            if (instruction == "forward") {
                x += std::stoi(value);
                y += (aim * std::stoi(value));
            } else if (instruction == "up") {
                aim -= std::stoi(value);
            } else if (instruction == "down") {
                aim += std::stoi(value);
            } else {
                std::cout << "Unknown command";
            }
        }
    } else {
        std::cout << "File not found";
    }

    result = x * y;
    std::cout << "Horizontal position: " << x << std::endl;
    std::cout << "Depth: " << y << std::endl;
    std::cout << "Aim: " << aim << std::endl;
    std::cout << "Output: " << result << std::endl;
}

int dive() {
    std::cout << "Day 2: Dive!" << std::endl;
    std::ifstream input;
    input.open("../inputs/02_dive.txt");

    dive_pt_one(input);
    input.clear();
    input.seekg(0);
    dive_pt_two(input);

    input.close();
    return 0;
}