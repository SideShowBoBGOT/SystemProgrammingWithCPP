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
        Models/TIdMixin.cpp Error/TGenderNoneException.cpp Error/TGenderNoneException.h Error/TAgeTooSmallException.cpp Error/TAgeTooSmallException.h
        Error/TVariadicNumberException.h
        Helpers/SStringLiteral.h
        Helpers/SVariadicElementsString.h
        Helpers/NNHelperFuncs.h
        Helpers/NNHelperFuncs.cpp
)

include_directories(external/CLI11/include)
include_directories(external/magic_enum/include)
