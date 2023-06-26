#pragma once
#include "Machine.h"
#include <iostream>

constexpr char SEMICOLON = ';';
constexpr char COMMA = ',';
constexpr char EMPTY = 'e';

Machine ParseMachineFromStream(std::istream &input) {
    Machine machine{};

    std::string line;
    std::vector<std::string> items;

    std::getline(input, line);
    Split(line, SEMICOLON, items);
    for (size_t i = 1; i < items.size(); ++i) {
        machine.finals.push_back(!items[i].empty());
    }

    items.clear();
    std::getline(input, line);
    Split(line, SEMICOLON, items);
    for (size_t i = 1; i < items.size(); ++i) {
        machine.states.push_back(items[i]);
    }

    if (machine.finals.size() != machine.states.size()) {
        machine.finals.push_back(false);
    }

    while (std::getline(input, line)) {
        items.clear();
        Split(line, SEMICOLON, items);

        if (items[0] == getString(EMPTY)) {
            for (size_t i = 1; i < items.size(); ++i) {
                std::vector<std::string> states;
                Split(items[i], COMMA, states);
                for (const auto &item: states) {
                    if (item != "-") {
                        machine.emptiness[machine.states[i - 1]].insert(item);
                    }
                }
            }
        } else {
            machine.paths.push_back(items[0]);
            for (size_t i = 1; i < items.size(); ++i) {
                std::vector<std::string> states;
                Split(items[i], COMMA, states);
                for (const auto &item: states) {
                    if (item != "-") {
                        machine.transitions[machine.states[i - 1]][items[0]].insert(item);
                    }
                }
            }
        }
    }

    return machine;
}
