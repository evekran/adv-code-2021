cmake_minimum_required(VERSION 3.21)
project(adv_code_2021)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        adv_code_2021
        main.cpp
        challenges/01_sonar_sweep/01_sonar_sweep.cpp challenges/01_sonar_sweep/01_sonar_sweep.h
        challenges/02_dive/02_dive.cpp challenges/02_dive/02_dive.h
)