set(SOURCES_TWO_WHEELED_ROBOT_SIMULATOR
	${two-wheeled-robot-simulator_SOURCE_DIR}/../../src/two-wheeled-robot-simulator/main.cpp
		../../src/two-wheeled-robot-simulator/ISimulator.h ../../src/two-wheeled-robot-simulator/Simulator.h ../../src/two-wheeled-robot-simulator/Simulator.cpp ../../src/two-wheeled-robot-simulator/RouteParser.h ../../src/two-wheeled-robot-simulator/RouteParser.cpp ../../src/two-wheeled-robot-simulator/RobotParameters.h ../../src/two-wheeled-robot-simulator/Route.h)

add_executable(two-wheeled-robot-simulator ${SOURCES_TWO_WHEELED_ROBOT_SIMULATOR})

if (UNIX)
	# link Dll
	set_target_properties(
		two-wheeled-robot-simulator
		PROPERTIES
			LINK_FLAGS "-lrt"
    )
endif(UNIX)
