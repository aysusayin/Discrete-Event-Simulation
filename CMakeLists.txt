cmake_minimum_required(VERSION 3.6)
project(project2_Aysu_Sayin_2016400051)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Customer.cpp Customer.h FirstModel.cpp FirstModel.h SecondModel.cpp SecondModel.h Event.cpp Event.h Cashier.cpp Cashier.h Barista.cpp Barista.h)
add_executable(project2_Aysu_Sayin_2016400051 ${SOURCE_FILES} FirstModel.cpp FirstModel.h SecondModel.cpp SecondModel.h Event.cpp Event.h Cashier.cpp Cashier.h Barista.cpp Barista.h)