#include <fstream>
#include <iostream>
#include <sstream>

#include "RouteParser.h"
#include "RobotParameters.h"
#include "Route.h"

using namespace std;

RouteParser::RouteParser():
m_robotParameters(std::make_shared<DataStructures::RobotParameters>()),
m_route(std::make_shared<DataStructures::Route>())
{}

bool RouteParser::parce(std::string fileName) {
    ifstream settingsFile(fileName);

    if (!settingsFile.is_open()) {
        cout << "Settings file " + fileName + " is not opened!" << endl;
        return false;
    }

    string line;

    while (std::getline(settingsFile, line)) {
        istringstream iss(line);
        if (!(iss >> m_robotParameters->b >> m_robotParameters->R)) {
            cout << "Error parsing robot parameters" << endl;
            return false;
        }
    }

    DataStructures::RoutePoint tempPoint;

    while (std::getline(settingsFile, line)) {
        istringstream iss(line);
        if (!(iss >> tempPoint.time >> tempPoint.tetta_1 >> tempPoint.tetta_2)) {
            cout << "Error parsing route" << endl;
            return false;
        }

        m_route->push_back(tempPoint);
    }



    return true;
}
