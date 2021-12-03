#include <iostream>
#include "challenges/01_sonar_sweep/01_sonar_sweep.h"
#include "challenges/02_dive/02_dive.h"
#include "challenges/03_binary_diagnostic/03_binary_diagnostic.h"

int main() {
    int challenge;

    std::cout << "Pick a day to run a challenge solution." << std::endl;
    std::cin >> challenge;

    switch (challenge) {
        case 1:
            return sonar_sweep();
        case 2:
            return dive();
        case 3:
            return binary_diagnostic();
        default:
            std::cout << "Invalid input." << std::endl;
            return 0;
    }
}
