#include <iostream>
#include "challenges/01_sonar_sweep/01_sonar_sweep.h"
#include "challenges/02_dive/02_dive.h"
#include "challenges/03_binary_diagnostic/03_binary_diagnostic.h"
#include "challenges/04_giant_squid/04_giant_squid.h"
#include "challenges/05_hydrothermal_venture/05_hydrothermal_venture.h"
#include "challenges/06_lanternfish/06_lanternfish.h"
#include "challenges/07_the_treachery_of_whales/07_the_treachery_of_whales.h"

int main() {
    int challenge;

    std::cout << "Pick a day to run a challenge solution." << std::endl;
    std::cin >> challenge;

    BaseChallenge *challenges[25] = {
            new SonarSweep(),
            new Dive(),
            new BinaryDiagnostic(),
            new GiantSquid(),
            new HydrothermalVenture(),
            new Lanternfish(),
            new TheTreacheryOfWhales(),
    };

    if (challenges[challenge - 1]) {
        challenges[challenge - 1]->run();
    } else {
        std::cout << "Invalid input." << std::endl;
    }

    return 0;
}
