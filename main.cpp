#include <iostream>
#include "challenges/01_sonar_sweep/01_sonar_sweep.cpp"
#include "challenges/02_dive/02_dive.cpp"
#include "challenges/03_binary_diagnostic/03_binary_diagnostic.cpp"
#include "challenges/04_giant_squid/04_giant_squid.cpp"

int main() {
    int challenge;

    std::cout << "Pick a day to run a challenge solution." << std::endl;
    std::cin >> challenge;

    switch (challenge) {
        case 1:
            SonarSweep().run();
            break;
        case 2:
            Dive().run();
            break;
        case 3:
            BinaryDiagnostic().run();
            break;
        case 4:
            GiantSquid().run();
            break;
        default:
            std::cout << "Invalid input." << std::endl;
            break;
    }

    return 0;
}
