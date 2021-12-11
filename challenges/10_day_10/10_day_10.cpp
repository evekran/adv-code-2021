#include <stack>
#include <set>
#include <map>
#include "../BaseChallenge.h"
#include "10_day_10.h"

using namespace std;

DayTen::DayTen() : BaseChallenge("10_day_10.txt", "Day 10") {}

void DayTen::part_one() {
    set<char> opening_chars = {'{', '(', '[', '<'};
    map<char, int> scores = {
            {')', 3},
            {']', 57},
            {'}', 1197},
            {'>', 25137},
    };
    stack<char> char_stack;
    long long counter = 0;

    for (auto &line: this->input_buffer) {
        for (auto &c : line) {
            if (opening_chars.find(c) != opening_chars.end()) {
                char_stack.push(c);
            } else {
                char opening_char = char_stack.top();
                if (c == '}' && opening_char != '{') {
                    counter += scores[c];
                    break;
                }
                if (c == ')' && opening_char != '(') {
                    counter += scores[c];
                    break;
                }
                if (c == ']' && opening_char != '[') {
                    counter += scores[c];
                    break;
                }
                if (c == '>' && opening_char != '<') {
                    counter += scores[c];
                    break;
                }
                char_stack.pop();
            }
        }
    }
    cout << counter;
}
void DayTen::part_two() {
    set<char> opening_chars = {'{', '(', '[', '<'};
    map<char, int> scores = {
            {')', 1},
            {']', 2},
            {'}', 3},
            {'>', 4},
    };
    vector<long long> total_scores;

    vector<stack<char>> valid_lines;
    for (auto &line: this->input_buffer) {
        stack<char> char_stack;
        bool is_valid = true;
        for (auto &c: line) {
            if (opening_chars.find(c) != opening_chars.end()) {
                char_stack.push(c);
            } else {
                char opening_char = char_stack.top();
                if (c == '}' && opening_char != '{') {
                    is_valid = false;
                    break;
                }
                if (c == ')' && opening_char != '(') {
                    is_valid = false;
                    break;
                }
                if (c == ']' && opening_char != '[') {
                    is_valid = false;
                    break;
                }
                if (c == '>' && opening_char != '<') {
                    is_valid = false;
                    break;
                }
                char_stack.pop();
            }
        }

        if (is_valid) {
            long long total_score = 0;
            while (!char_stack.empty()) {
                char c = char_stack.top();
                if (c == '{') {
                    total_score *= 5;
                    total_score += scores['}'];
                }
                if (c == '(') {
                    total_score *= 5;
                    total_score += scores[')'];
                }
                if (c == '[') {
                    total_score *= 5;
                    total_score += scores[']'];
                }
                if (c == '<') {
                    total_score *= 5;
                    total_score += scores['>'];
                }
                char_stack.pop();
            }
            total_scores.push_back(total_score);
        }
    }

    std::sort(total_scores.begin(), total_scores.end());
    long middle = round(total_scores.size() / 2);
    cout << total_scores[middle];
}