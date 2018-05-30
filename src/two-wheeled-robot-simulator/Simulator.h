#pragma once

#include "ISimulator.h"

class Simulator : public ISimulator {
public:
    bool init(const std::string& fileName) override;
    Position run() override;
};