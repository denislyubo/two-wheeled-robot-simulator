#include <iostream>
#include <memory>
#include <string>

#include "ISimulator.h"
#include "Simulator.h"

using namespace std;

std::string parceArguments(int argc, char* argv[]) {
	if (argc != 2) {
		cout << "Incorrect number of parameters" << endl;

		return "";
	}

	return argv[1];
}

int main(int argc, char* argv[]) {

	auto traceFilePath = parceArguments(argc, argv);

	unique_ptr<ISimulator> simulator(new Simulator);
	simulator->init(traceFilePath);
	auto pos = simulator->run();

    cout << "Position (x, y, alpha): " << pos.x << " " << pos.y << " " << pos.alpha << endl;

	return 0;
}
