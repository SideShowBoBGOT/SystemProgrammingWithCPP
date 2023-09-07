#include "TIdNotExistException.h"

#include <format>

TIdNotExistException::TIdNotExistException(unsigned id) {
    m_sMessage = std::format(R"(Id "{}" does not exist)", id);
}

const char* TIdNotExistException::what() const noexcept {
    return m_sMessage.c_str();
}


