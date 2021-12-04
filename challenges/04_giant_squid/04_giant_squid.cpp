#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <sstream>

using namespace std;

#include "../BaseChallenge.h"

class GiantSquid : public BaseChallenge {
private:
    void part_one() override {
        vector<string> numbers_drawn;
        std::stringstream data(this->input_buffer[0]);
        std::string number_row;
        while (std::getline(data, number_row, ',')) {
            numbers_drawn.push_back(number_row);
        }

        vector<vector<string>> boards = get_boards();

        vector<string> winner_board;
        for (const auto& drawn : numbers_drawn) {
            for (auto & board_iterator : boards) {
                vector<string> board = board_iterator;
                for (int row_iterator = 0; row_iterator < board.size(); row_iterator++) {
                    if (drawn == board[row_iterator]) {
                        board[row_iterator] = "X";
                    }
                    board_iterator = board;
                }
            }

            for (const auto& board : boards) {
                if (GiantSquid::is_winner(board)) {
                    GiantSquid::print_board(board, drawn);
                    return;
                }
            }
        }
    }

    vector<vector<string>> get_boards() {
        vector<vector<string>> boards;

        string number;
        vector<string> board_input;
        for (const auto &line: input_buffer) {
            if (line[1] == ',') {
                continue;
            }

            if (line.empty()) {
                boards.push_back(board_input);
                board_input.clear();
            }

            stringstream board_row(line);
            while (getline(board_row, number, ' ')) {
                if (!number.empty()) {
                    board_input.push_back(number);
                }
            }
        }
        return boards;
    }

    void part_two() override {
        vector<string> numbers_drawn;
        std::stringstream data(this->input_buffer[0]);
        std::string number_row;
        while (std::getline(data, number_row, ',')) {
            numbers_drawn.push_back(number_row);
        }

        vector<vector<string>> boards = get_boards();

        vector<string> winner_board;
        for (const auto& drawn : numbers_drawn) {
            for (auto & board_iterator : boards) {
                vector<string> board = board_iterator;
                for (int row_iterator = 0; row_iterator < board.size(); row_iterator++) {
                    if (drawn == board[row_iterator]) {
                        board[row_iterator] = "X";
                    }
                    board_iterator = board;
                }
            }

            for (int board_iterator = 0; board_iterator < boards.size(); board_iterator++) {
                vector<string> board = boards[board_iterator];
                if (GiantSquid::is_winner(board)) {
                    if (boards.size() == 1) {
                        GiantSquid::print_board(board, drawn);
                        return;
                    } else {
                        boards.erase(boards.begin() + board_iterator);
                    }
                }
            }


        }
    }

    static void print_board(vector<string> board, const string& drawn_number) {
        cout << "-----" << endl;
        int n = stoi(drawn_number);
        int sum = 0;

        for (int row_index = 0; row_index < 5; row_index++) {
            for (int position = 0; position < 5; position++) {
                string number = board[row_index * 5 + position];
                if (number != "X") {
                    sum += stoi(number);
                }
                if (number.size() == 1) {
                    number += " ";
                }
                cout << number << " ";
            }
            cout << endl;
        }

        cout << "Number drawn: " << drawn_number << endl;
        cout << "Sum: " << sum << endl;
        cout << "Result: " << n * sum << endl;
        cout << "-----" << endl;
    }

    static bool is_winner(vector<string> board) {
        // Check rows
        for (int row_index = 0; row_index < 5; row_index++) {
            int counter = 0;
            for (int position = 0; position < 5; position++) {
                string number = board[row_index * 5 + position];
                if (number == "X") {
                    counter++;
                }
            }
            if (counter == 5) {
                return true;
            }
        }

        // Check columns
        for (int column_index = 0; column_index < 5; column_index++) {
            int counter = 0;
            for (int position = 0; position < 5; position++) {
                string number = board[position * 5 + column_index];
                if (number == "X") {
                    counter++;
                }
            }
            if (counter == 5) {
                return true;
            }
        }

        return false;
    }

public:
    GiantSquid() : BaseChallenge("04_giant_squid.txt", "Day 4: Giant Squid") {}
};
