set(SOURCES_TWO_WHEELED_ROBOT_SIMULATOR
	${two-wheeled-robot-simulator_SOURCE_DIR}/../../src/two-wheeled-robot-simulator/main.cpp
)

add_executable(two-wheeled-robot-simulator ${SOURCES_TWO_WHEELED_ROBOT_SIMULATOR})

if (UNIX)
	# link Dll
	set_target_properties(
		two-wheeled-robot-simulator
		PROPERTIES
			LINK_FLAGS "-lrt"
    )
endif(UNIX)
