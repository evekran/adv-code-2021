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
        challenges/05_day_five/05_day_five.cpp challenges/05_day_five/05_day_five.h
        challenges/06_day_six/06_day_six.cpp challenges/06_day_six/06_day_six.h
        challenges/BaseChallenge.cpp challenges/BaseChallenge.h
)