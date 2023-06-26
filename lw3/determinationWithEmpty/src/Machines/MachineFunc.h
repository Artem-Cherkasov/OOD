#pragma once
#include "DeterministicMachine/DeterministicMachine.h"
#include "Machine/Machine.h"
#include <queue>

const std::string NEW_STATE_TITLE = "S";

std::string GetStateTitle(int n) {
    return NEW_STATE_TITLE + std::to_string(n);
}

Machine ConvertDeterministicMachineToMachine(const DeterministicMachine &deterministicMachine) {
    Machine machine{};
    for (int i = 0; i < deterministicMachine.states.size(); ++i) {
        auto state = deterministicMachine.states[i];
        auto itemMap = deterministicMachine.transitions.find(i);
        if (itemMap == deterministicMachine.transitions.end()) {
            continue;
        }

        MachineTransitionState tempMap;
        for (const auto &item: itemMap->second) {
            auto indexIt = std::find(deterministicMachine.states.begin(), deterministicMachine.states.end(), item.second);
            if (indexIt != deterministicMachine.states.end()) {
                tempMap[item.first].insert(GetStateTitle(int(indexIt - deterministicMachine.states.begin())));
            }
        }
        auto title = GetStateTitle(i);
        machine.transitions[title] = tempMap;
        machine.states.push_back(title);
    }
    machine.paths = deterministicMachine.paths;
    for (const auto &item: deterministicMachine.finals) {
        machine.finals.push_back(item);
    }
    return machine;
}

void AddEmptyTransitions(Machine &machine) {
    for (const auto &item: machine.states) {
        std::set<std::string> set;
        std::queue<std::string> queue;
        std::vector<std::string> vector;
        set.insert(item);
        queue.push(item);
        vector.push_back(item);
        while (!queue.empty()) {
            auto it = queue.front();
            queue.pop();
            auto stateIt = machine.emptiness.find(it);
            if (stateIt == machine.emptiness.end()) {
                continue;
            }
            auto state = stateIt->second;
            set.insert(state.begin(), state.end());
            for (const auto &stateItem: state) {
                if (std::find(vector.begin(), vector.end(), stateItem) == vector.end()) {
                    queue.push(stateItem);
                    vector.push_back(stateItem);
                }
            }
        }
        machine.emptiness[item].insert(set.begin(), set.end());
    }
}
