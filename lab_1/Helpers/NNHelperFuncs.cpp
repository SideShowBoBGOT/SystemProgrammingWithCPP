#include "NNHelperFuncs.h"

std::string NNHelperFuncs::TitledString(const std::string& str) {
	return static_cast<char>(std::toupper(str[0])) + str.substr(1);
}
