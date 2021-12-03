#include <iostream>
#include <string>
#include <numeric>
#include "../BaseChallenge.h"


class Dive : public BaseChallenge {
private:
    void part_one() override {
        int result ;
        std::string command;

        int x = 0, y = 0;

        for (const auto& line : this->input_buffer) {
            command = line;
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
        result = x * y;
        std::cout << "Horizontal position: " << x << std::endl;
        std::cout << "Depth: " << y << std::endl;
        std::cout << "Output: " << result << std::endl;
    }

    void part_two() override {
        std::string command;

        int result ;
        int x = 0, y = 0, aim = 0;

        std::vector<int> window;

        for (const auto& line : this->input_buffer) {
            command = line;
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

        result = x * y;
        std::cout << "Horizontal position: " << x << std::endl;
        std::cout << "Depth: " << y << std::endl;
        std::cout << "Aim: " << aim << std::endl;
        std::cout << "Output: " << result << std::endl;
    }

public:
    Dive() : BaseChallenge("02_dive.txt",  "Day 2: Dive!") {}
};
