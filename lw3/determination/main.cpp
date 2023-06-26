#include "src/Args/Args.h"
#include "src/Determination/Determination.h"
#include "src/Machines/Machine/MachineParser.h"
#include "src/Machines/Machine/MachineSaving.h"
#include <iostream>

int main(int argc, char *argv[]) {
    try {
        auto args = ParseArgs(argc, argv);
        std::ifstream input(args.input);
        std::ofstream output(args.output);
        CheckFileOpen(input, output);
        auto machine = ParseMachineFromStream(input, args.type);
        machine = Determination(machine);
        SaveMachineToStreamAsCsv(output, machine);
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }

    return 0;
}
