#pragma once

#include <vector>

namespace DataStructures {
    struct RoutePoint {
        float time;
        float tetta_1;
        float tetta_2;
    };

    using Route = std::vector<RoutePoint>;
}
