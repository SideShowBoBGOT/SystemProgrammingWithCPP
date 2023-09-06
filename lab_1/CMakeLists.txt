cmake_minimum_required(VERSION 3.25)
project(lab_1)

set(CMAKE_CXX_STANDARD 23)

add_executable(${PROJECT_NAME} main.cpp TWorker.cpp TWorker.h EGender.h
        TLibrary.h
        TLibrary.cpp
        TUser.h
        TUser.cpp)
