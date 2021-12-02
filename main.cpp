#include <iostream>
#include "challenges/01_sonar_sweep/01_sonar_sweep.h"
#include "challenges/02_dive/02_dive.h"
#include "challenges/03_xxx/03_xxx.h"

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
            return xxx();
        default:
            std::cout << "Invalid input." << std::endl;
            return 0;
    }
}
