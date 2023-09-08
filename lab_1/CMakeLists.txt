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
        Helpers/TStringLiteral.h
        Helpers/SVariadicElementsString.h
)