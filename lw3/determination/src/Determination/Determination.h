#pragma once
#include "../Common/CommonFunc.h"
#include "../Common/CommonType.h"
#include "../Machines/DeterministicMachine/DeterministicMachine.h"
#include "../Machines/Machine/Machine.h"
#include "../Machines/MachineFunc.h"
#include <fstream>
#include <iostream>
#include <queue>

DeterministicMachine DeterminationImpl(const Machine &machine) {
    DeterministicMachine deterministicMachine{};
    std::queue<std::set<std::string>> queue;
    if (!machine.states.empty()) {
        queue.push({machine.states[0]});
    }

    while (!queue.empty()) {
        auto item = queue.front();
        queue.pop();

        DeterministicMachineTransitionState tempTransitions;
        std::vector<std::set<std::string>> tempStates;
        for (const auto &it: item) {
            auto valueItem = machine.transitions.find(it);
            if (valueItem == machine.transitions.end()) {
                continue;
            }

            for (const auto &transitionItem: valueItem->second) {
                tempTransitions[transitionItem.first].insert(transitionItem.second.begin(), transitionItem.second.end());
            }
        }

        for (const auto &tempTransitionsItem: tempTransitions) {
            tempStates.push_back(tempTransitionsItem.second);
        }

        auto index = int(deterministicMachine.states.size());
        deterministicMachine.transitions[index] = tempTransitions;
        deterministicMachine.states.push_back(item);
        deterministicMachine.paths = machine.paths;

        for (const auto &tempStatesItem: tempStates) {
            if (std::find(deterministicMachine.states.begin(), deterministicMachine.states.end(), tempStatesItem) == deterministicMachine.states.end()) {
                queue.push(tempStatesItem);
            }
        }
    }
    auto finalIt = std::find(machine.finals.begin(), machine.finals.end(), true);
    if (finalIt != machine.finals.end()) {
        auto final = machine.states[finalIt - machine.finals.begin()];
        for (const auto &item: deterministicMachine.states) {
            deterministicMachine.finals.push_back(item.find(final) != item.end());
        }
    }
    return deterministicMachine;
}

Machine Determination(const Machine &machine) {
    auto deterministicMachine = DeterminationImpl(machine);
    return ConvertDeterministicMachineToMachine(deterministicMachine);
}
