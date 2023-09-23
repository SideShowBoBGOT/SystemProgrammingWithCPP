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
CXXFLAGS := -std=c++23 ${INCLUDE_FLAGS}
DLLS := -lboost_serialization

main.out: main.o NNHelperFuncs.o TAgeTooSmallException.o TBook.o TCustomCLI.o TIdException.o TIdMixin.o TLibrary.o TUser.o TUserBook.o TWorker.o
	${CXX} ${CXXFLAGS} $^ -o $@ ${DLLS}
	
%.o: ${SOURCE_DIR}/%.cpp
	${CXX} ${CXXFLAGS}  -c $< -o $@

clean:
	rm *.o *.out