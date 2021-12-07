#include <iostream>
#include <string>
#include <utility>

using namespace std;

#include "../BaseChallenge.h"
#include "05_hydrothermal_venture.h"

class Cloud {

public:
    explicit Cloud(string params) {
        // 309,347 -> 309,464
        std::string delimiter = " -> ";
        string start_coords = params.substr(0, params.find(delimiter));
        params.erase(0, params.find(delimiter) + delimiter.length());
        string end_coords = params.substr(0, params.find(delimiter));

        delimiter = ",";
        int x_start_input = stoi(start_coords.substr(0, start_coords.find(delimiter)));
        start_coords.erase(0, start_coords.find(delimiter) + delimiter.length());
        int y_start_input = stoi(start_coords);


        int x_end_input = stoi(end_coords.substr(0, end_coords.find(delimiter)));
        end_coords.erase(0, end_coords.find(delimiter) + delimiter.length());
        int y_end_input = stoi(end_coords);

        this->x_start = x_start_input;
        this->x_end = x_end_input;

        this->y_start = y_start_input;
        this->y_end = y_end_input;

        if (this->is_horizontal() || this->is_vertical()) {
            if (x_end_input < x_start_input) {
                this->x_start = x_end_input;
                this->x_end = x_start_input;
            }

            if (y_end_input < y_start_input) {
                this->y_start = y_end_input;
                this->y_end = y_start_input;
            }
        }
    }

    bool is_horizontal() const {
        return this->y_start == this->y_end;
    }

    bool is_vertical() const {
        return this->x_start == this->x_end;
    }

    int x_end = -1;
    int y_end = -1;
    int x_start = -1;
    int y_start = -1;
};

void HydrothermalVenture::part_one() {
    int grid[1000][1000];
    for (auto & i : grid) {
        for (int & j : i) {
            j = 0;
        }
    }

    int intersect_count = 0;
    for (const auto &line: input_buffer) {
        Cloud cloud = Cloud(line);

        if (cloud.is_horizontal()) {
            int y = cloud.y_end;
            for (int x = cloud.x_start; x <= cloud.x_end; x++) {
                if (grid[y][x] == 0) {
                    grid[y][x] = 1;
                } else if (grid[y][x] == 1) {
                    intersect_count++;
                    grid[y][x] = 2;
                }
            }
        } else if (cloud.is_vertical()) {
            int x = cloud.x_end;
            for (int y = cloud.y_start; y <= cloud.y_end; y++) {
                if (grid[y][x] == 0) {
                    grid[y][x] = 1;
                } else if (grid[y][x] == 1) {
                    intersect_count++;
                    grid[y][x] = 2;
                }
            }
        }
    }

    cout << "Intersections:" << intersect_count << endl;
}

void HydrothermalVenture::part_two() {
    int grid[1000][1000];
    for (auto & i : grid) {
        for (int & j : i) {
            j = 0;
        }
    }

    int intersect_count = 0;
    for (const auto &line: input_buffer) {
        Cloud cloud = Cloud(line);

        if (cloud.is_horizontal()) {
            int y = cloud.y_end;
            for (int x = cloud.x_start; x <= cloud.x_end; x++) {
                if (grid[y][x] == 0) {
                    grid[y][x] = 1;
                } else if (grid[y][x] == 1) {
                    intersect_count++;
                    grid[y][x] = 2;
                }
            }
        } else if (cloud.is_vertical()) {
            int x = cloud.x_end;
            for (int y = cloud.y_start; y <= cloud.y_end; y++) {
                if (grid[y][x] == 0) {
                    grid[y][x] = 1;
                } else if (grid[y][x] == 1) {
                    intersect_count++;
                    grid[y][x] = 2;
                } else if (grid[y][x] == 2) {
                    grid[y][x] = 3;
                }
            }
        } else {
            int x_start = cloud.x_start;
            int x_end = cloud.x_end;
            int y_start = cloud.y_start;
            int y_end = cloud.y_end;

            if (x_end < x_start) {
                x_start = cloud.x_end;
                y_start = cloud.y_end;
                x_end = cloud.x_start;
                y_end = cloud.y_start;
            }

            int y = y_start;
            for (int x = x_start; x <= x_end; x++) {
                if (grid[y][x] == 0) {
                    grid[y][x] = 1;
                } else if (grid[y][x] == 1) {
                    intersect_count++;
                    grid[y][x] = 2;
                } else if (grid[y][x] == 2) {
                    grid[y][x] = 3;
                }
                if (y_start > y_end) {
                    y--;
                } else {
                    y++;
                }
            }

        }
    }

    cout << "Intersections:" << intersect_count << endl;
}

HydrothermalVenture::HydrothermalVenture() : BaseChallenge("05_hydrothermal_venture.txt", "Day 5: Hydrothermal Venture") {}
