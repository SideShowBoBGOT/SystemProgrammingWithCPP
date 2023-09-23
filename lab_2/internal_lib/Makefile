# local
SOURCE_DIR := src
INCLUDE_DIR := include

# external libs
EXTERNAL_LIBS_DIR := external

# magic_enum
MAGIC_ENUM_INCLUDE_DIR := ${EXTERNAL_LIBS_DIR}/magic_enum/include

# CLI11
CLI11_DIR = ${EXTERNAL_LIBS_DIR}/CLI11
CLI11_INCLUDE_DIR := ${CLI11_DIR}/include

# includes
INCLUDE_FLAGS := -I include -I ${MAGIC_ENUM_INCLUDE_DIR} -I ${CLI11_INCLUDE_DIR}

CXX := g++
CXXFLAGS := -std=c++23 -fPIC ${INCLUDE_FLAGS}
DLLS := -lboost_serialization

OBJECT_FILES := NNHelperFuncs.o TAgeTooSmallException.o TBook.o TCustomCLI.o TIdException.o TIdMixin.o TLibrary.o TUser.o TUserBook.o TWorker.o

STATIC_LIB_NAME := liblab_2_static.a
DYNAMIC_LIB_NAME := liblab_2_dynamic

default: main.out

main.out: main.o ${OBJECT_FILES}
	${CXX} ${CXXFLAGS} $^ -o $@ ${DLLS}

static_lib: liblab_2_static.a

liblab_2_static.a: ${OBJECT_FILES}
	ar rcs $@ $^ 

dynamic_lib: liblab_2_dynamic.so

liblab_2_dynamic.so: ${OBJECT_FILES}
	${CXX} -shared $^ -o $@ 

%.o: ${SOURCE_DIR}/%.cpp
	${CXX} ${CXXFLAGS}  -c $< -o $@

clean:
	rm *.o *.out *.a *.so