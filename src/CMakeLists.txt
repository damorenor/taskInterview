cmake_minimum_required(VERSION "3.0")

set(Boost_USE_STATIC_LIBS        ON) # only find static libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
find_package(Boost 1.36.0 COMPONENTS date_time)
if(Boost_FOUND)
  project(client)
  include_directories(${Boost_INCLUDE_DIRS})
  add_executable(client taskClient.cpp)
  target_link_libraries(client ${Boost_LIBRARIES})
endif()



