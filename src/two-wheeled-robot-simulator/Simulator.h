#pragma once

#include <memory>

#include "ISimulator.h"
#include "Commands.h"
#include "RobotParameters.h"
#include "KinematicModel.h"

template <typename T>
class Simulator : public ISimulator<T> {
public:
    bool init(const std::string& fileName) override;
    std::tuple<T, T, T> run(bool logPath = false, std::string logFileName = "path.txt") override;

private:
    std::shared_ptr<DataStructures::Commands<T>> m_route;
    std::shared_ptr<DataStructures::RobotParameters> m_robotParameters;
    std::unique_ptr<KinematicModel<T>> m_model;
};

template
class Simulator<double>;