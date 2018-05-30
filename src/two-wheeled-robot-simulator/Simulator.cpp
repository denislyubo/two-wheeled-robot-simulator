#include "Simulator.h"
#include "RouteParser.h"

bool Simulator::init(const std::string &fileName) {
    RouteParser parser;
    if (!parser.parce(fileName))
        return false;

    m_robotParameters = parser.getRobotParameters();
    m_route = parser.getCommands();

    m_model.reset(new KinematicModel);
    m_model->init(m_robotParameters);

    return true;
}

ISimulator::Position Simulator::run() {
    std::tuple<float, float, float> startRoutePoint{0, 0, 0};
    std::tuple<float, float, float> curPos{0, 0, 0};
    DataStructures::Command prevCommand{};

    for (const auto& command : *m_route) {
        auto newPos = m_model->makeStep(curPos, prevCommand, command);

        prevCommand = command;
        curPos = newPos;
    }

    return {std::get<0>(curPos), std::get<1>(curPos), std::get<2>(curPos)};
}

