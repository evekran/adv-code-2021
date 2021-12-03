#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>
using namespace std;


void part_one(ifstream &input) {
    string line;
    int common_bits[12] = {0,0,0,0,0, 0,0,0,0,0, 0,0};

    if (input.is_open()) {
        while ( getline (input,line) )
        {
            for (int i = 0; i < 12; i++) {
                if (line[i] == '0') {
                    common_bits[i] -= 1;
                } else {
                    common_bits[i] += 1;
                }
            }
        }

        std::ostringstream gamma_bin_stream;
        std::ostringstream epsilon_bin_stream;
        for (int common_bit : common_bits) {
            if (common_bit >= 0) {
                gamma_bin_stream << 1;
                epsilon_bin_stream << 0;
            } else {
                gamma_bin_stream << 0;
                epsilon_bin_stream << 1;
            }
        }

        std::string gamma_bin(gamma_bin_stream.str());
        std::string epsilon_bin(epsilon_bin_stream.str());

        int gamma_value = stoi(gamma_bin, nullptr, 2);
        int epsilon_value = stoi(epsilon_bin, nullptr, 2);

        cout << "Gamma value: " << gamma_value << endl;
        cout << "Epsilon value: " << epsilon_value << endl;
        cout << "Power consumption: " << epsilon_value * gamma_value << endl;
    } else {
        cout << "File not found";
    }
}

int find_common_bit(std::vector<string> &readings, int position = 0, bool is_least = false) {
    int frequency = 0;
    for (auto reading : readings) {
        if (reading[position] == '0') {
            frequency -= 1;
        } else {
            frequency += 1;
        }
    }

    int common_bit = 0;
    if (frequency >= 0) {
        common_bit = 1;
    }
    if (not is_least) {
        return common_bit;
    }

    return common_bit == 0 ? 1 : 0;
}

int vector_to_int(std::vector<string> &v) {
    std::ostringstream bin_stream;
    for (auto & e : v) {
        bin_stream << e;
    }
    std::string bin_string(bin_stream.str());
    int gamma_value = stoi(bin_string, 0, 2);

    return gamma_value;
}

void part_two(std::ifstream &input) {
    string line;
    std::vector<string> readings;
    std::vector<string> oxygen_readings;
    std::vector<string> co2_readings;

    if (input.is_open()) {
        while ( getline (input,line) )
        {
            oxygen_readings.push_back(line);
            co2_readings.push_back(line);
        }

        int bit_iterator = 0;
        std::vector<string> oxygen_readings_temp;
        while (oxygen_readings.size() != 1) {
            oxygen_readings_temp.clear();
            int common_bit = find_common_bit(oxygen_readings, bit_iterator);

            for (auto oxygen_reading : oxygen_readings) {
                int bit = 0;
                if (oxygen_reading[bit_iterator] == '1') {
                    bit = 1;
                }
                if (bit == common_bit) {
                    oxygen_readings_temp.push_back(oxygen_reading);
                }
            }

            oxygen_readings = oxygen_readings_temp;
            bit_iterator++;
        }

        bit_iterator = 0;
        std::vector<string> co2_readings_temp;
        while (co2_readings.size() != 1) {
            co2_readings_temp.clear();
            int common_bit = find_common_bit(co2_readings, bit_iterator);
            if (common_bit == 0) {
                common_bit = 1;
            } else {
                common_bit = 0;
            }

            for (auto co2_reading : co2_readings) {
                int bit = 0;
                if (co2_reading[bit_iterator] == '1') {
                    bit = 1;
                }
                if (bit == common_bit) {
                    co2_readings_temp.push_back(co2_reading);
                }
            }

            co2_readings = co2_readings_temp;
            bit_iterator++;
        }

        int oxygen_rating = vector_to_int(oxygen_readings);
        int co2_rating = vector_to_int(co2_readings);

        cout << "Oxygen rating: " << oxygen_rating << endl;
        cout << "C02 rating: " << co2_rating << endl;
        cout << "Life support rating: " << oxygen_rating * co2_rating << endl;
    } else {
        cout << "File not found";
    }
}

int binary_diagnostic() {
    cout << "Day 3: Binary Diagnostic" << endl;
    ifstream input;
    input.open("../inputs/03_binary_diagnostic.txt");

    part_one(input);
    input.clear();
    input.seekg(0);

    cout << endl;
    part_two(input);

    input.close();
    return 0;
}