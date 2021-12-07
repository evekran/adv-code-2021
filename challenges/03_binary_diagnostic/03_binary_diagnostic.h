#ifndef DAY_03_BINARY_DIAGNOSTIC
#define DAY_03_BINARY_DIAGNOSTIC
#include "../BaseChallenge.h"
#include <iostream>
#include <string>
using namespace std;

class BinaryDiagnostic : public BaseChallenge {
private:
    void part_one() override;
    void part_two() override;
    static int find_common_bit(std::vector<string> &readings, int position = 0);
    static int vector_to_int(std::vector<string> &v);

public:
    BinaryDiagnostic();
};
#endif
