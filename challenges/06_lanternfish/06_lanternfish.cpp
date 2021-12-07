#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <sstream>

using namespace std;

#include "../BaseChallenge.h"
#include "06_lanternfish.h"

void Lanternfish::part_one() {
    string input_data = this->input_buffer[0];
    std::stringstream data(input_data);

    vector<int> lanternfish;
    std::string age;
    while (std::getline(data, age, ',')) {
        lanternfish.push_back(stoi(age));
    }

    long long fish_ages[9] = {0,0,0,0,0,0,0,0, 0};
    for (auto &fish_age : lanternfish) {
        fish_ages[fish_age] += 1;
    }

    for (int day = 0; day < 80; day++) {
        long long new_fish = fish_ages[0];
        for (int a = 0; a < 9; a++) {
            fish_ages[a - 1] = fish_ages[a];
        }
        fish_ages[6] += new_fish;
        fish_ages[8] = new_fish;
    }

    print_fish_count(fish_ages);
}

void Lanternfish::part_two() {
    vector<int> lanternfish;

    string input_data = this->input_buffer[0];
    std::stringstream data(input_data);
    std::string age;
    while (std::getline(data, age, ',')) {
        lanternfish.push_back(stoi(age));
    }

    long long fish_ages[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (auto &fish_age: lanternfish) {
        fish_ages[fish_age] += 1;
    }

    for (int day = 0; day < 256; day++) {
        long long new_fish = fish_ages[0];
        for (int a = 0; a < 9; a++) {
            fish_ages[a - 1] = fish_ages[a];
        }
        fish_ages[6] += new_fish;
        fish_ages[8] = new_fish;
    }

    print_fish_count(fish_ages);
}

void Lanternfish::print_fish_count(const long long fish_ages[9]) {
    unsigned long long size = 0;
    for (long long a = 0; a < 9; a++) {
        size += fish_ages[a];
    }
    cout << size << endl;
}

Lanternfish::Lanternfish() : BaseChallenge("06_lanternfish.txt", "Day 6: Lanternfish") {}

