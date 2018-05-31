#include <fstream>

#include "Simulator.h"
#include "RouteParser.h"

using namespace std;

template <typename T>
bool Simulator<T>::init(const std::string &fileName) {
    RouteParser<T> parser;
    if (!parser.parse(fileName))
        return false;

    m_robotParameters = parser.getRobotParameters();
    m_route = parser.getCommands();

    m_model.reset(new KinematicModel<T>);
    m_model->init(m_robotParameters);

    return true;
}

template <typename T>
std::tuple<T, T, T> Simulator<T>::run(bool logPath, std::string logFileName) {
    std::tuple<T, T, T> startRoutePoint{0, 0, 0};
    std::tuple<T, T, T> curPos{0, 0, 0};
    DataStructures::Command<T> prevCommand{};

    std::ofstream file;

    if (logPath)
        file.open(logFileName);

    for (const auto& command : *m_route) {
        auto newPos = m_model->makeStep(curPos, prevCommand, command);

        prevCommand = command;
        curPos = newPos;

        if (logPath)
            file << get<0>(curPos) << " " << get<1>(curPos) << " " << get<2>(curPos) << std::endl;
    }

    return curPos;
}

