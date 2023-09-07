#ifndef LAB_1_TAGETOOSMALLEXCEPTION_H
#define LAB_1_TAGETOOSMALLEXCEPTION_H

#include <exception>
#include <string>

class TAgeTooSmallException : std::exception {
    public:
    TAgeTooSmallException(unsigned age, unsigned minAge);

    public:
    virtual const char* what() const noexcept override;

    protected:
    std::string m_sMessage;
};


#endif //LAB_1_TAGETOOSMALLEXCEPTION_H
