cmake_minimum_required(VERSION 2.8)
project(HttpServer)
set(sources main.cpp
	Server.cpp
	ConnectionManager.cpp
	Connection.cpp
	RequestHandler.cpp
	)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
add_executable(${PROJECT_NAME} ${sources})
target_link_libraries(${PROJECT_NAME} ws2_32)
