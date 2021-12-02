#include <iostream>
#include "challenges/01_sonar_sweep/01_sonar_sweep.h"
#include "challenges/02_dive/02_dive.h"

int main() {
    int challenge;

    std::cout << "Pick a day to run a challenge solution." << std::endl;
    std::cin >> challenge;

    switch (challenge) {
        case 1:
            return sonar_sweep();
        case 2:
            return dive();
        default:
            std::cout << "Invalid input." << std::endl;
            return 0;
    }
}
