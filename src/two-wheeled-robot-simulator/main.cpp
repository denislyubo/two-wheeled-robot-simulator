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

	unique_ptr<ISimulator<double>> simulator(new Simulator<double>);
	if(!simulator->init(traceFilePath))
        cout << "Initialization completed unsuccessfully" << endl;
	auto pos = simulator->run(true);

    cout << "Position (x, y, alpha): " << get<0>(pos) << " " << get<1>(pos) << " " << get<2>(pos) << endl;

	return 0;
}
