#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include "../BaseChallenge.h"

class SonarSweep : public BaseChallenge {
private:
    void part_one() override {
        int result = 0;
        int current_depth;
        int previous_depth = 0;

        for (const auto& line : this->input_buffer) {
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

        std::cout << "Output: " << result << std::endl;
    }

    void part_two() override {
        int result = 0;
        int depth_value;
        int current_depth;
        int previous_depth = 0;

        std::vector<int> window;

        for (const auto& line : this->input_buffer) {
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

        std::cout << "Output: " << result << std::endl;
    }

public:
    SonarSweep() : BaseChallenge("01_sonar_sweep.txt",  "Day 1: Sonar Sweep") {}
};
