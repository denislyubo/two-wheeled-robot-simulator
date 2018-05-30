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

    if(!traceFilePath.size())
        return 1;

	unique_ptr<ISimulator> simulator(new Simulator);
	if(!simulator->init(traceFilePath))
        cout << "Initialization completed unsuccessfully" << endl;
	auto pos = simulator->run();

    cout << "Position (x, y, alpha): " << pos.x << " " << pos.y << " " << pos.alpha << endl;

	return 0;
}
