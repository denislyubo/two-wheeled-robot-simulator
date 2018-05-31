#pragma once

#include <string>
#include <memory>
#include <fstream>
#include <iostream>
#include <sstream>

#include "RobotParameters.h"
#include "Commands.h"


template <typename T>
class RouteParser {
public:
    RouteParser();
    bool parse(std::string fileName);

    std::shared_ptr<DataStructures::RobotParameters> getRobotParameters() {
        return m_robotParameters;
    }
    std::shared_ptr<DataStructures::Commands<T>> getCommands() {
        return m_commands;
    }

private:
    std::shared_ptr<DataStructures::RobotParameters> m_robotParameters{};
    std::shared_ptr<DataStructures::Commands<T>> m_commands{};
};

template <typename T>
RouteParser<T>::RouteParser():
        m_robotParameters(std::make_shared<DataStructures::RobotParameters>()),
        m_commands(std::make_shared<DataStructures::Commands<T>>())
{}

template <typename T>
bool RouteParser<T>::parse(std::string fileName) {
    std::ifstream settingsFile(fileName);

    if (!settingsFile.is_open()) {
        std::cout << "Settings file " + fileName + " is not opened!" << std::endl;
        return false;
    }

    std::string line;

    std::getline(settingsFile, line);
    std::istringstream iss(line);
    if (!(iss >> m_robotParameters->b >> m_robotParameters->R)) {
        std::cout << "Error parsing robot parameters" << std::endl;
        return false;
    }


    DataStructures::Command<T> tempPoint;

    while (std::getline(settingsFile, line)) {
        std::istringstream iss(line);
        if (!(iss >> tempPoint.time >> tempPoint.tetta_1 >> tempPoint.tetta_2)) {
            std::cout << "Error parsing route" << std::endl;
            return false;
        }

        m_commands->push_back(tempPoint);
    }



    return true;
}

