#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <list>
#include "../09_day_9/09_day_9.h"

using namespace std;

class LowPoint {
public:
    LowPoint(int x, int y, int h) {
        this->x = x;
        this->y = y;
        this->h = h;
    }

    int y;
    int x;
    int h;
};

DayNine::DayNine() : BaseChallenge("09_day_9.txt", "Day 9") {}

void DayNine::part_one() {
    vector<string> input = input_buffer;
    const int map_width = 100;
    const int map_height = 100;
    int height_map[map_height][map_width];

    for (int i = 0; i < map_height; i++) {
        string l = input[i];
        for (int j = 0; j < map_width; j++) {
            height_map[i][j] = (int)l[j] - 48;
        }
    }

    int risk_level = 0;
    for (int i = 0; i < map_height; i++) {
        for (int j = 0; j < map_width; j++) {
            int top = i-1;
            int bottom = i+1;
            int left = j-1;
            int right = j+1;

            int i_h = height_map[i][j];
            int top_h = 10;
            int bottom_h = 10;
            int left_h = 10;
            int right_h = 10;
            if (top >= 0) {
                top_h = height_map[top][j];
            }
            if (bottom <= map_height) {
                bottom_h = height_map[bottom][j];
            }
            if (left >= 0) {
                left_h = height_map[i][left];
            }
            if (right <= map_width) {
                right_h = height_map[i][right];
            }

            if (i == 0) {
                if (i_h < bottom_h && i_h < left_h && i_h < right_h) {
                    risk_level += i_h + 1;
                }
            } else if (i == map_height - 1) {
                if (i_h < top_h && i_h < left_h && i_h < right_h) {
                    risk_level += i_h + 1;
                }
            } else if (j == 0) {
                if (i_h < top_h && i_h < bottom_h && i_h < right_h) {
                    risk_level += i_h + 1;
                }
            } else if (j == map_width - 1) {
                if (i_h < top_h && i_h < bottom_h && i_h < left_h) {
                    risk_level += i_h + 1;
                }
            } else {
                if (i_h < top_h && i_h < bottom_h && i_h < left_h && i_h < right_h) {
                    risk_level += i_h + 1;
                }
            }
        }
    }

    cout << risk_level << endl;
}

void DayNine::part_two() {
    this->read_map();
    const int map_width = height_map[0].size();
    const int map_height = height_map.size();

    vector<LowPoint> low_points;
    for (int i = 0; i < map_height; i++) {
        for (int j = 0; j < map_width; j++) {
            int top = i-1;
            int bottom = i+1;
            int left = j-1;
            int right = j+1;

            int i_h = height_map[i][j];
            int top_h = 10;
            int bottom_h = 10;
            int left_h = 10;
            int right_h = 10;
            if (top >= 0) {
                top_h = height_map[top][j];
            }
            if (bottom < map_height) {
                bottom_h = height_map[bottom][j];
            }
            if (left >= 0) {
                left_h = height_map[i][left];
            }
            if (right < map_width) {
                right_h = height_map[i][right];
            }

            if (i == 0) {
                if (i_h < bottom_h && i_h < left_h && i_h < right_h) {
                    low_points.emplace_back(LowPoint(j, i, i_h));
                }
            } else if (i == map_height - 1) {
                if (i_h < top_h && i_h < left_h && i_h < right_h) {
                    low_points.emplace_back(LowPoint(j, i, i_h));
                }
            } else if (j == 0) {
                if (i_h < top_h && i_h < bottom_h && i_h < right_h) {
                    low_points.emplace_back(LowPoint(j, i, i_h));
                }
            } else if (j == map_width - 1) {
                if (i_h < top_h && i_h < bottom_h && i_h < left_h) {
                    low_points.emplace_back(LowPoint(j, i, i_h));
                }
            } else {
                if (i_h < top_h && i_h < bottom_h && i_h < left_h && i_h < right_h) {
                    low_points.emplace_back(LowPoint(j, i, i_h));
                }
            }
        }
    }

    vector<int> basin_sizes;
    vector<set<string>> basins;
    for (auto &lp: low_points) {
        set<string> basin_members;
        basin_members = search_basin(lp.x, lp.y, basin_members);
        basins.push_back(basin_members);
        basin_sizes.push_back(basin_members.size());
    }

    sort(basin_sizes.begin(), basin_sizes.end());
    cout << "Result: " << basin_sizes[basin_sizes.size() - 1] * basin_sizes[basin_sizes.size() - 2] * basin_sizes[basin_sizes.size() - 3] << endl;
}

set<string> DayNine::search_basin(int x, int y, set<string> basin_members) {
    if (x >= height_map[0].size() || x < 0) {
        return basin_members;
    }
    if (y >= height_map.size() || y < 0) {
        return basin_members;
    }

    if (height_map[y][x] == 9) {
        return basin_members;
    }

    string v = to_string(x) + "-" + to_string(y);
    basin_members.insert(v);

    if (x - 1 >= 0) {
        if (height_map[y][x] < height_map[y][x - 1] && height_map[y][x - 1] <= 9) {
            set<string> s = search_basin(x - 1, y, basin_members);
            basin_members.insert(s.begin(), s.end());
        }
    }

    if (x + 1 < height_map[0].size()) {
        if (height_map[y][x] < height_map[y][x + 1] && height_map[y][x + 1] <= 9) {
            set<string> s = search_basin(x + 1, y, basin_members);
            basin_members.insert(s.begin(), s.end());
        }
    }

    if (y - 1 >= 0) {
        if (height_map[y][x] < height_map[y - 1][x] && height_map[y - 1][x] <= 9) {
            set<string> s = search_basin(x, y - 1, basin_members);
            basin_members.insert(s.begin(), s.end());
        }
    }

    if (y + 1 < height_map.size()) {
        if (height_map[y][x] < height_map[y + 1][x] && height_map[y + 1][x] <= 9) {
            set<string> s = search_basin(x, y + 1, basin_members);
            basin_members.insert(s.begin(), s.end());
        }
    }

    return basin_members;
}

void DayNine::read_map() {
    for (string &line : input_buffer) {
        vector<int> height_v;
        std::list<char> height_list(line.begin(), line.end());
        for (char h: height_list) {
            int x = (int)h - 48;
            height_v.emplace_back(x);
        }

        height_map.emplace_back(height_v);
    }
}
