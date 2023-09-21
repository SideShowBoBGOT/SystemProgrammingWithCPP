cmake_minimum_required(VERSION 3.25)
project(lab_1)

set(CMAKE_CXX_STANDARD 23)

add_executable(${PROJECT_NAME} main.cpp src/TWorker.cpp include/TWorker.h include/EGender.h
        include/TLibrary.h
        src/TLibrary.cpp
        include/TUser.h
        src/TUser.cpp
        include/TBook.h
        src/TBook.cpp
        include/TIdMixin.h
        src/TIdMixin.cpp src/TAgeTooSmallException.cpp include/TAgeTooSmallException.h
        include/TIdException.h
        include/NNHelperFuncs.h
        src/NNHelperFuncs.cpp
        include/TCustomCLI.h
        src/TCustomCLI.cpp
        include/TUserBook.h
        src/TUserBook.cpp
        src/TIdException.cpp
        include/SOverloadVariant.h
)

find_package(Boost 1.74 COMPONENTS program_options system filesystem serialization REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC ${Boost_LIBRARIES})

include_directories(external/CLI11/include)
include_directories(external/magic_enum/include)
