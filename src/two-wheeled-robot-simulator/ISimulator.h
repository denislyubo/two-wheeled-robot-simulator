#pragma once

#include <string>

template <typename T>
class ISimulator {
public:
    virtual ~ISimulator() = default;
    /**
     *
     * @param fileName - path to file with robot settings and sequence of commands
     * @return true if initialisation was successful
     */
    virtual bool init(const std::string& fileName) = 0;
    /**
     * @details Returns final position of trajectory
     * @return (x, y, alpha)
     */
    virtual std::tuple<T, T, T> run(bool logPath = false, std::string logFileName = "path.txt") = 0;
};