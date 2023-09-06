#include <iostream>
#include "TWorker.h"

#include <optional>

int main() {
	auto w = TWorker();
	
	auto v = w.Gender(EGender::None);
	
	std::get_if<std::monostate>(&v);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
