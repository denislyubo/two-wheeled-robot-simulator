#pragma once

#include <string>

class ISimulator {
public:
    struct Position {
        float x;
        float y;
        float alpha;
    };

    virtual ~ISimulator() = default;

    virtual bool init(const std::string& fileName) = 0;
    virtual Position run() = 0;
};