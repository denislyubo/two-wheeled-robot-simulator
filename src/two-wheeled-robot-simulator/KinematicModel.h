#pragma once

#include <memory>
#include <tuple>
#include <math.h>

#include "RobotParameters.h"
#include "Commands.h"

#define PI 3.14159265

template <typename T>
class KinematicModel {
public:
    void init(std::shared_ptr<DataStructures::RobotParameters> params);
    std::tuple<T, T, T> makeStep(std::tuple<T, T, T> currentPos, DataStructures::Command<T> prevCommand, DataStructures::Command<T> command);

private:
    T b;
    T R;
};

template <typename T>
void KinematicModel<T>::init(std::shared_ptr<DataStructures::RobotParameters> params) {
    b = params->b;
    R = params->R;
}

template <typename T>
std::tuple<T, T, T> KinematicModel<T>::makeStep(std::tuple<T, T, T> currentPos, DataStructures::Command<T> prevCommand, DataStructures::Command<T> command) {
    auto delta_t = command.time - prevCommand.time;
    if(delta_t < 1e-6)
        return currentPos;

    auto omega_1 = (command.tetta_1 - prevCommand.tetta_1) / delta_t;
    auto omega_2 = (command.tetta_2 - prevCommand.tetta_2) / delta_t;

    auto tetta = std::get<2>(currentPos) + (R / b) * (omega_1 - omega_2) * delta_t;
    auto v = (R / 2.) * (omega_1 + omega_2);

    auto y = std::get<1>(currentPos) + v * sin(tetta/* * PI/180*/) * delta_t;
    auto x = std::get<0>(currentPos) + v * cos(tetta/* * PI/180*/) * delta_t;

    std::tuple<T, T, T> newPos{x, y, tetta};
    return newPos;
}