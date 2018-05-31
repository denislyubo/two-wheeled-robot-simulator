#pragma once

#include <string>
#include <memory>

#include "RobotParameters.h"
#include "Commands.h"


class RouteParser {
public:
    RouteParser();
    bool parse(std::string fileName);

    std::shared_ptr<DataStructures::RobotParameters> getRobotParameters() {
        return m_robotParameters;
    }
    std::shared_ptr<DataStructures::Commands> getCommands() {
        return m_commands;
    }

private:
    std::shared_ptr<DataStructures::RobotParameters> m_robotParameters{};
    std::shared_ptr<DataStructures::Commands> m_commands{};
};
