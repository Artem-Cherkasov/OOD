#pragma once
#include <iostream>

struct Args {
    std::string input;
    std::string output;
};

Args ParseArgs(int argc, char *argv[]) {
    if (argc != 3) {
        throw std::invalid_argument("Invalid argument count");
    }

    return {
            .input = argv[1],
            .output = argv[2],
    };
}
