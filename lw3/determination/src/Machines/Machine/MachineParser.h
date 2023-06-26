#pragma once
#include "../../Common/CommonType.h"
#include "Machine.h"
#include <iostream>

constexpr char SEPARATOR = '|';

void ParseTransition(const std::string &string, Machine &machine, DeterminationType type) {
    auto currentState = machine.states[machine.states.size() - 1];
    std::vector<std::string> transitions;
    Split(string, SEPARATOR, transitions);
    for (auto &item: transitions) {
        trim(item);
        std::string in;
        std::string st;
        if (type == DeterminationType::LEFT) {
            in = getString(item[item.size() - 1]);
            st = item.substr(0, item.size() - 1);
            machine.transitions[st][in].insert(currentState);
        } else {
            in = getString(item[0]);
            st = item.substr(1, item.size() - 1);
            machine.transitions[currentState][in].insert(st);
        }

        if (std::find(machine.paths.begin(), machine.paths.end(), in) == machine.paths.end()) {
            machine.paths.push_back(in);
        }
    }
}

Machine ParseMachineFromStream(std::istream &input, DeterminationType type) {
    Machine machine{};

    std::string line;
    if (type == DeterminationType::LEFT) {
        machine.states.emplace_back("");
        machine.finals.emplace_back(false);
    }
    while (std::getline(input, line)) {
        std::istringstream iss(line);
        std::string state;
        iss >> state;
        machine.states.push_back(state);
        machine.finals.emplace_back(false);

        std::string last;
        iss >> last;

        std::getline(iss, last);
        ParseTransition(last, machine, type);
    }
    if (type == DeterminationType::RIGHT) {
        machine.states.emplace_back("");
        machine.finals.emplace_back(true);
    }
    if (type == DeterminationType::LEFT && machine.finals.size() > 1) {
        machine.finals[1] = true;
    }

    return machine;
}
