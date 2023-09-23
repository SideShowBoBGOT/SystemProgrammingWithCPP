INTERNAL_LIB_DIR = ../internal_lib
EXTERNAL_LIBS_DIR := ${INTERNAL_LIB_DIR}/external
MAGIC_ENUM_INCLUDE_DIR := ${EXTERNAL_LIBS_DIR}/magic_enum/include
CLI11_DIR = ${EXTERNAL_LIBS_DIR}/CLI11
CLI11_INCLUDE_DIR := ${CLI11_DIR}/include

CXX := g++

INCLUDE_DIR := ${INTERNAL_LIB_DIR}/include
INCLUDE_FLAGS := -I ${INCLUDE_DIR} -I ${MAGIC_ENUM_INCLUDE_DIR} -I ${CLI11_INCLUDE_DIR}

CXXFLAGS := -std=c++23 ${INCLUDE_FLAGS}
DLLS := -lboost_serialization

default: main.out

main.out: main.cpp
	${CXX} ${CXXFLAGS} $^ -o $@ -L=${LD_LIBRARY_PATH} -llab_2_dynamic ${DLLS}

clean:
	rm *.o *.out *.txt