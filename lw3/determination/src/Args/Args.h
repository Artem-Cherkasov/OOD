#pragma once
#include "../Common/CommonType.h"
#include <iostream>

struct Args {
    DeterminationType type;
    std::string input;
    std::string output;
};

DeterminationType ParseType(const std::string &type) {
    if (type == "left") {
        return DeterminationType::LEFT;
    }
    if (type == "right") {
        return DeterminationType::RIGHT;
    }

    throw std::invalid_argument("Invalid type");
}

Args ParseArgs(int argc, char *argv[]) {
    if (argc != 4) {
        throw std::invalid_argument("Invalid argument count");
    }

    return {
            .type = ParseType(argv[1]),
            .input = argv[2],
            .output = argv[3],
    };
}
