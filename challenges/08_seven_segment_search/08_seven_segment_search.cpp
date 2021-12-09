#include "08_seven_segment_search.h"
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>


class Signal {
private:
    string signal_input;
    string output_value;

public:
    explicit Signal(string line) {
        std::string delimiter = " | ";
        signal_input = line.substr(0, line.find(delimiter));
        line.erase(0, line.find(delimiter) + delimiter.length());
        output_value = line.substr(0, line.find(delimiter));
    }

    int occurrence_counter = 0;

    string decode_signal() {
        vector<string> encoded_digits;
        std::stringstream data(signal_input);
        std::string encoded_digit;

        map<int, string> signals;
        while (std::getline(data, encoded_digit, ' ')) {
            sort(encoded_digit.begin(), encoded_digit.end());
            int signal_size = int(encoded_digit.size());
            if (signal_size == 2) {
                signals[1] = encoded_digit;
                continue;
            }

            if (signal_size == 3) {
                signals[7] = encoded_digit;
                continue;
            }

            if (signal_size == 4) {
                signals[4] = encoded_digit;
                continue;
            }

            if (signal_size == 7) {
                signals[8] = encoded_digit;
                continue;
            }
            encoded_digits.push_back(encoded_digit);
        }

        for (auto & i : encoded_digits) {
            encoded_digit = i;
            if (encoded_digit.size() == 6) {
                set<char> encoded_set(begin(encoded_digit), end(encoded_digit));
                set<char> four_set(begin(signals[4]), end(signals[4]));
                if (std::includes(encoded_set.begin(), encoded_set.end(),four_set.begin(), four_set.end())) {
                    signals[9] = encoded_digit;
                } else {
                    set<char> one_set(begin(signals[1]), end(signals[1]));
                    if (std::includes(encoded_set.begin(), encoded_set.end(),one_set.begin(), one_set.end())) {
                        signals[0] = encoded_digit;
                    } else {
                        signals[6] = encoded_digit;
                    }
                }
            }
        }

        for (auto & i : encoded_digits) {
            encoded_digit = i;
            if (encoded_digit.size() == 5) {
                set<char> encoded_set(begin(encoded_digit), end(encoded_digit));
                set<char> six_set(begin(signals[6]), end(signals[6]));
                if (std::includes(six_set.begin(), six_set.end(), encoded_set.begin(), encoded_set.end())) {
                    signals[5] = encoded_digit;
                } else {
                    set<char> one_set(begin(signals[1]), end(signals[1]));
                    if (std::includes(encoded_set.begin(), encoded_set.end(),one_set.begin(), one_set.end())) {
                        signals[3] = encoded_digit;
                    } else {
                        signals[2] = encoded_digit;
                    }
                }
            }
        }

        map<string, int> signal_to_value;
        for (auto const& x : signals)
        {
            signal_to_value[x.second] = x.first;
        }

        std::stringstream output(output_value);
        string decoded_value;
        while (std::getline(output, encoded_digit, ' ')) {
            sort(encoded_digit.begin(), encoded_digit.end());
            string d = std::to_string(signal_to_value[encoded_digit]);
            if (d == "1" || d == "4" || d == "7" || d == "8") {
                this->occurrence_counter++;
            }
            decoded_value += d;
        }

        return decoded_value;
    }

};

SevenSegmentSearch::SevenSegmentSearch() : BaseChallenge("08_seven_segment_search.txt",
                                                         "Day 8: Seven Segment Search") {}

void SevenSegmentSearch::part_one() {
    vector <string> input = this->input_buffer;
    vector <Signal*> signals;

    int occurrence_counter = 0;
    for (const auto &line: input) {
        auto * signal_line = new Signal(line);
        signals.push_back(signal_line);
        signal_line->decode_signal();
        occurrence_counter += signal_line->occurrence_counter;
    }

    cout << occurrence_counter << endl;
}

void SevenSegmentSearch::part_two() {
    vector <string> input = this->input_buffer;
    vector <Signal*> signals;

    int total = 0;
    for (const auto &line: input) {
        auto * signal_line = new Signal(line);
        signals.push_back(signal_line);
        total += std::stoi(signal_line->decode_signal());
    }

    cout << total << endl;
}