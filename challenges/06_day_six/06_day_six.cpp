#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <sstream>

using namespace std;

#include "../BaseChallenge.h"

class DaySix : public BaseChallenge {
private:


    void part_one() override {
        for (const auto &line: input_buffer) {
            cout << line << endl;
        }
        cout << "PART ONE" << endl;
    }

    void part_two() override {
        cout << "PART TWO" << endl;
    }


public:
    DaySix() : BaseChallenge("06_day_six.txt", "Day 6: Day Six") {}
};
