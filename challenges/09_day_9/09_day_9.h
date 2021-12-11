#ifndef ADV_CODE_2021_09_DAY_9_H
#define ADV_CODE_2021_09_DAY_9_H
#include "../BaseChallenge.h"
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

class DayNine : public BaseChallenge {
private:
    void part_one() override;
    void part_two() override;

    vector<vector<int>> height_map;
    void read_map();
public:
    DayNine();
    set<string> search_basin(int x, int y, set<string> basin_members);
};
#endif //ADV_CODE_2021_09_DAY_9_H
