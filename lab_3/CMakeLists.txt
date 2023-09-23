cmake_minimum_required(VERSION 3.26)
project(lab_3)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(lab_3 main.cpp)
target_link_libraries(lab_3
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

