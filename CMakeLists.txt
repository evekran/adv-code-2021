cmake_minimum_required(VERSION 3.21)
project(adv_code_2021)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        adv_code_2021
        main.cpp
        challenges/01_sonar_sweep/01_sonar_sweep.cpp challenges/01_sonar_sweep/01_sonar_sweep.h
        challenges/02_dive/02_dive.cpp challenges/02_dive/02_dive.h
        challenges/03_binary_diagnostic/03_binary_diagnostic.cpp challenges/03_binary_diagnostic/03_binary_diagnostic.h
        challenges/04_giant_squid/04_giant_squid.cpp challenges/04_giant_squid/04_giant_squid.h
        challenges/05_hydrothermal_venture/05_hydrothermal_venture.cpp challenges/05_hydrothermal_venture/05_hydrothermal_venture.h
        challenges/06_lanternfish/06_lanternfish.cpp challenges/06_lanternfish/06_lanternfish.h
        challenges/07_the_treachery_of_whales/07_the_treachery_of_whales.cpp challenges/07_the_treachery_of_whales/07_the_treachery_of_whales.h
        challenges/08_seven_segment_search/08_seven_segment_search.cpp challenges/08_seven_segment_search/08_seven_segment_search.h
        challenges/BaseChallenge.cpp challenges/BaseChallenge.h
)