#pragma once
#include "../../Common/CommonFunc.h"
#include <fstream>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using MachineTransitionState = std::unordered_map<std::string, std::set<std::string>>;

struct Machine {
    std::vector<std::string> states;
    std::vector<std::string> paths;
    std::vector<bool> finals;
    std::unordered_map<std::string, MachineTransitionState> transitions;
    std::unordered_map<std::string, std::set<std::string>> emptiness;
};
