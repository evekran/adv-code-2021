#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>

void sonar_sweep_pt_one(std::ifstream &input) {
    std::string line;

    int result = 0;
    int current_depth;
    int previous_depth = 0;

    if (input.is_open()) {
        while ( getline (input,line) )
        {
            current_depth = std::stoi( line);
            if (previous_depth == 0) {
                std::cout << "(N/A - no previous measurement)" << std::endl;
            } else {
                if (current_depth > previous_depth) {
                    result += 1;
                    std::cout << "(increased)" << std::endl;
                } else {
                    std::cout << "(decreased)" << std::endl;
                }
            }

            previous_depth = current_depth;
        }
    } else {
        std::cout << "File not found";
    }

    std::cout << "Output: " << result << std::endl;
}

void sonar_sweep_pt_two(std::ifstream &input) {
    std::string line;

    int result = 0;
    int depth_value;
    int current_depth;
    int previous_depth = 0;
    std::vector<int> window;

    if (input.is_open()) {
        while ( getline (input,line) )
        {
            depth_value = std::stoi( line);
            window.push_back(depth_value);
            if (window.size() == 4) {
                window.erase(window.begin());
            }

            current_depth = std::accumulate(window.begin(), window.end(), 0);
            if (window.size() == 3) {
                std::cout << current_depth << std::endl;
                if (previous_depth == 0) {
                    std::cout << "(N/A - no previous sum)" << std::endl;
                } else {
                    if (current_depth > previous_depth) {
                        result += 1;
                        std::cout << "(increased)" << std::endl;
                    } else {
                        std::cout << "(decreased)" << std::endl;
                    }
                }

                previous_depth = current_depth;
            } else {
                std::cout << current_depth << std::endl;
                std::cout << "(N/A - no previous sum)" << std::endl;
            }
        }
    } else {
        std::cout << "File not found";
    }

    std::cout << "Output: " << result << std::endl;
}

int sonar_sweep() {
    std::cout << "Day 1: Sonar Sweep" << std::endl;
    std::ifstream input;
    input.open("../inputs/01_sonar_sweep.txt");

    sonar_sweep_pt_one(input);
    input.clear();
    input.seekg(0);
    sonar_sweep_pt_two(input);

    input.close();
    return 0;
}