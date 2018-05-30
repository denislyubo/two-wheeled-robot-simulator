#pragma once

#include <vector>

namespace DataStructures {
    struct Command {
        float time;
        float tetta_1;
        float tetta_2;
    };

    using Commands = std::vector<Command>;
}
