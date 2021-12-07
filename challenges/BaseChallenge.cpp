#include "BaseChallenge.h"

#include <utility>

BaseChallenge::BaseChallenge(std::string filename, std::string challenge_name) {
    this->challenge_name = std::move(challenge_name);
    this->filename = std::move(filename);
}

void BaseChallenge::read_input() {
    this->input.open("../inputs/" + this->filename);
    std::string line;
    if (this->input.is_open()) {
        while ( getline (input,line) )
        {
            this->input_buffer.push_back(line);
        }
    } else {
        std::cout << "File not found" << std::endl;
    }

    this->input.close();
}

void BaseChallenge::run() {
    std::cout << this->challenge_name << std::endl;
    this->read_input();

    std::cout << "PART ONE" << std::endl;
    this->part_one();
    std::cout << std::endl;
    std::cout << "PART TWO" << std::endl;
    this->part_two();
}

void BaseChallenge::part_one() {}
void BaseChallenge::part_two() {}
