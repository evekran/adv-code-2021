#ifndef DAY_04_GIANT_SQUID
#define DAY_04_GIANT_SQUID
#include "../BaseChallenge.h"
#include <iostream>
#include <string>
using namespace std;

class GiantSquid : public BaseChallenge {
private:
    void part_one() override;
    void part_two() override;
public:
    GiantSquid();
};
#endif
