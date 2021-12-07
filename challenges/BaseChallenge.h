#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#ifndef ADV_CODE_2021_BASECHALLENGE_H
#define ADV_CODE_2021_BASECHALLENGE_H


class BaseChallenge {
protected:
    std::ifstream input;
    std::vector<std::string> input_buffer;
    std::string filename;
    std::string challenge_name;

    void read_input();

    virtual void part_one();
    virtual void part_two();
public:
    BaseChallenge(std::string filename, std::string challenge_name);

    virtual void run();
};


#endif //ADV_CODE_2021_BASECHALLENGE_H
