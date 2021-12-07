#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include "../BaseChallenge.h"
#include "01_sonar_sweep.h"

void SonarSweep::part_one() {
    std::vector<std::string> input = this->input_buffer;

    int result = 0;
    int current_depth;
    int previous_depth = 0;

    for (const auto &line: input) {
        current_depth = std::stoi(line);
        if (previous_depth != 0) {
            if (current_depth > previous_depth) {
                result += 1;
            }
        }

        previous_depth = current_depth;
    }

    std::cout << "Output: " << result << std::endl;
}

void SonarSweep::part_two() {
    std::vector<std::string> input = this->input_buffer;

    int result = 0;
    int depth_value;
    int current_depth;
    int previous_depth = 0;

    std::vector<int> window;

    for (const auto& line : input) {
        depth_value = std::stoi( line);
        window.push_back(depth_value);
        if (window.size() == 4) {
            window.erase(window.begin());
        }

        current_depth = std::accumulate(window.begin(), window.end(), 0);
        if (window.size() == 3) {
            if (previous_depth != 0) {
                if (current_depth > previous_depth) {
                    result += 1;
                }
            }
            previous_depth = current_depth;
        }
    }

    std::cout << "Output: " << result << std::endl;
}

SonarSweep::SonarSweep() : BaseChallenge("01_sonar_sweep.txt",  "Day 1: Sonar Sweep") {}