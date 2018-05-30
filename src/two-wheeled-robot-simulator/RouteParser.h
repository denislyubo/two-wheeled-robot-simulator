#pragma once

#include <string>
#include <memory>

#include "RobotParameters.h"
#include "Route.h"


class RouteParser {
public:
    RouteParser();
    bool parce(std::string fileName);

    std::shared_ptr<DataStructures::RobotParameters> getRobotParameters() {
        return m_robotParameters;
    }
    std::shared_ptr<DataStructures::Route> getRoute() {
        return m_route;
    }

private:
    std::shared_ptr<DataStructures::RobotParameters> m_robotParameters{};
    std::shared_ptr<DataStructures::Route> m_route{};
};
