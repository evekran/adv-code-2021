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
    vector<vector<string>> get_boards();
    static bool is_winner(vector<string> board);
    static void print_board(vector<string> board, const string &drawn_number);
};
#endif
