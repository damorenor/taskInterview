cmake_minimum_required(VERSION "3.0")

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lboost_system -std=c++17")

project(client)
project(server)
add_executable(
	client
	taskClient.cpp
)

add_executable(
	server
	taskServerUnix.cpp
)