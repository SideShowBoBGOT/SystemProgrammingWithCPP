#include "TGenderNoneException.h"
#include <string>

static constexpr std::string_view s_sMessage = "Gender can not be None";

const char *TGenderNoneException::what() const noexcept {
    return s_sMessage.data();
}
