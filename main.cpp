#include <iostream>
#include "challenges/01_sonar_sweep/01_sonar_sweep.h"
#include "challenges/02_dive/02_dive.h"
#include "challenges/03_binary_diagnostic/03_binary_diagnostic.h"
#include "challenges/04_giant_squid/04_giant_squid.h"
#include "challenges/05_hydrothermal_venture/05_hydrothermal_venture.h"
#include "challenges/06_lanternfish/06_lanternfish.h"
#include "challenges/07_the_treachery_of_whales/07_the_treachery_of_whales.h"
#include "challenges/08_seven_segment_search/08_seven_segment_search.h"
#include "challenges/09_day_9/09_day_9.h"
#include "challenges/10_day_10/10_day_10.h"

int main() {
    int challenge;

    std::cout << "Pick a day to run a challenge solution." << std::endl;
//    std::cin >> challenge;

    challenge = 9;
    BaseChallenge *challenges[25] = {
            new SonarSweep(),
            new Dive(),
            new BinaryDiagnostic(),
            new GiantSquid(),
            new HydrothermalVenture(),
            new Lanternfish(),
            new TheTreacheryOfWhales(),
            new SevenSegmentSearch(),
            new DayNine(),
            new DayTen(),
    };

    if (challenges[challenge - 1]) {
        challenges[challenge - 1]->run();
    } else {
        std::cout << "Undefined challenge: " << challenge << std::endl;
    }

    return 0;
}
