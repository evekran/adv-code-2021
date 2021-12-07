#ifndef DAY_06_LANTERNFISH
#define DAY_06_LANTERNFISH
#include "../BaseChallenge.h"
#include <iostream>
#include <string>
using namespace std;

class Lanternfish : public BaseChallenge {
private:
    void part_one() override;
    void part_two() override;
public:
    Lanternfish();

    static void print_fish_count(const long long int *fish_ages);
};
#endif
