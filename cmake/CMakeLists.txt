cmake_minimum_required (VERSION 3.4)

project (simulator)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/out")

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -msse -msse2 -Wall -fPIC -m64 -pthread -Wunknown-pragmas -fvisibility=hidden")
set (CMAKE_C_FLAGS	"${CMAKE_C_FLAGS} -m64 -fPIC")
set (CMAKE_EXE_LINKER_FLAGS	"${CMAKE_EXE_LINKER_FLAGS} -m64 -fPIC")
set (CMAKE_MODULE_LINKER_FLAGS "${CMAKE_MODULE_LINKER_FLAGS} -m64 -fPIC")
set (CMAKE_SHARED_LINKER_FLAGS  "${CMAKE_SHARED_LINKER_FLAGS} -m64 -fPIC")

add_subdirectory(two-wheeled-robot-simulator)
