cmake_minimum_required(VERSION 3.25)
project(lab_1)

set(CMAKE_CXX_STANDARD 23)

add_executable(${PROJECT_NAME} main.cpp Models/TWorker.cpp Models/TWorker.h Models/EGender.h
        Controllers/TLibrary.h
        Controllers/TLibrary.cpp
        Models/TUser.h
        Models/TUser.cpp
        Models/TBook.h
        Models/TBook.cpp
        Models/TIdMixin.h
        Models/TIdMixin.cpp Error/TAgeTooSmallException.cpp Error/TAgeTooSmallException.h
        Error/TVariadicNumberException.h
        Helpers/SStringLiteral.h
        Helpers/SVariadicElementsString.h
        Helpers/NNHelperFuncs.h
        Helpers/NNHelperFuncs.cpp
        Views/TCustomCLI.h
        Views/TCustomCLI.cpp
)

find_package(Boost 1.74 COMPONENTS program_options REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC ${Boost_LIBRARIES})

include_directories(external/CLI11/include)
include_directories(external/magic_enum/include)
