#pragma once
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using DeterministicMachineTransitionState = std::unordered_map<std::string, std::set<std::string>>;

struct DeterministicMachine {
    std::vector<std::set<std::string>> states;
    std::vector<std::string> paths;
    std::unordered_map<int, DeterministicMachineTransitionState> transitions;
    std::vector<bool> finals;
};
