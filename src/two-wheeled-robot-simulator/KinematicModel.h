#pragma once

#include <memory>
#include <tuple>

#include "RobotParameters.h"
#include "Commands.h"

class KinematicModel {
public:
    void init(std::shared_ptr<DataStructures::RobotParameters> params);
    std::tuple<float, float, float> makeStep(std::tuple<float, float, float> currentPos, DataStructures::Command prevCommand, DataStructures::Command command);

private:
    float b;
    float R;
};