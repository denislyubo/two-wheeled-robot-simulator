#pragma once

#include <memory>

#include "ISimulator.h"
#include "Commands.h"
#include "RobotParameters.h"
#include "KinematicModel.h"

class Simulator : public ISimulator {
public:
    bool init(const std::string& fileName) override;
    Position run() override;

private:
    std::shared_ptr<DataStructures::Commands> m_route;
    std::shared_ptr<DataStructures::RobotParameters> m_robotParameters;
    std::unique_ptr<KinematicModel> m_model;
};