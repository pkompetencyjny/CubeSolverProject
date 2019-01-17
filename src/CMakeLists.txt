cmake_minimum_required(VERSION 3.3.1)

project(CubeSolver)

find_package(OpenCV    3.2.0    REQUIRED)

include_directories(
    ${OpenCV_INCLUDE_DIRS}
)

add_executable(CubeSolver
	main.cpp
	Cam.hpp
	Vision.cpp
	ExtractColors.hpp
	Vision.hpp
	CubeSolver.cpp
	CubeSolver.hpp
	ExtractColors.cpp
	Utils.cpp
	Utils.hpp
)

target_link_libraries(CubeSolver
    ${OpenCV_LIBS}
)