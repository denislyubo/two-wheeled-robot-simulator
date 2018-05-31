#pragma once

#include <vector>

namespace DataStructures {
    template <typename T>
    struct Command {
        T time;
        T tetta_1;
        T tetta_2;
    };

    template <typename T>
    using Commands = std::vector<Command<T>>;
}
