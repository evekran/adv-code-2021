#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <sstream>
#include "07_the_treachery_of_whales.h"

TheTreacheryOfWhales::TheTreacheryOfWhales() : BaseChallenge("07_the_treachery_of_whales.txt", "Day 7: The Treachery of Whales") {}

void TheTreacheryOfWhales::part_one() {
    string input = input_buffer[0];
    std::stringstream data(input);

    vector<int> fuel_list;
    std::string fuel_value;
    while (std::getline(data, fuel_value, ',')) {
        fuel_list.push_back(stoi(fuel_value));
    }

    sort(fuel_list.begin(), fuel_list.end());
    int min_position = fuel_list[0];
    int max_position = fuel_list[fuel_list.size() - 1];
    cout << "Min: " << min_position << endl;
    cout << "Max: " << max_position << endl;

    int fuel_counter;
    vector<int> fuel_prices;

    for (int i = min_position; i <= max_position; i++) {
        int fuel_price = 0;
        for (auto f : fuel_list) {
            if (f == i) {
                fuel_counter = 0;
            } else if (f > i) {
                fuel_counter = f - i;
            } else {
                fuel_counter = i - f;
            }

            fuel_price += fuel_counter;
        }
        fuel_prices.push_back(fuel_price);
    }

    sort(fuel_prices.begin(), fuel_prices.end());
    cout  << "Total fuel: " << fuel_prices[0] << endl;
}

void TheTreacheryOfWhales::part_two() {
    string input = input_buffer[0];
    std::stringstream data(input);

    vector<int> fuel_list;
    std::string fuel_value;
    while (std::getline(data, fuel_value, ',')) {
        fuel_list.push_back(stoi(fuel_value));
    }

    sort(fuel_list.begin(), fuel_list.end());
    int min_position = fuel_list[0];
    int max_position = fuel_list[fuel_list.size() - 1];
    cout << "Min: " << min_position << endl;
    cout << "Max: " << max_position << endl;

    int fuel_counter;
    vector<int> fuel_prices;

    for (int i = min_position; i <= max_position; i++) {
        int fuel_price = 0;
        for (auto f : fuel_list) {
            if (f == i) {
                fuel_counter = 0;
            } else if (f > i) {
                fuel_counter = f - i;
            } else {
                fuel_counter = i - f;
            }
            int min = 0;
            int max = fuel_counter;
            fuel_counter = ((max-min)+1) * (min + max) / 2;

            fuel_price += fuel_counter;
        }
        fuel_prices.push_back(fuel_price);
    }

    sort(fuel_prices.begin(), fuel_prices.end());
    cout << "Total fuel: " << fuel_prices[0] << endl;
}