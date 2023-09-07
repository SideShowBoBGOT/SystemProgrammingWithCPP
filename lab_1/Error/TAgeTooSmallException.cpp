#include "TAgeTooSmallException.h"

#include <format>

TAgeTooSmallException::TAgeTooSmallException(unsigned age, unsigned minAge) {
    m_sMessage = std::format(R"(Age "{}" is less than minimal age "{}")", age, minAge);
}

const char* TAgeTooSmallException::what() const noexcept {
    return m_sMessage.c_str();
}