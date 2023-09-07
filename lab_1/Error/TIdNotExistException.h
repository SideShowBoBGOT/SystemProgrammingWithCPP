#ifndef LAB_1_TIDNOTEXISTEXCEPTION_H
#define LAB_1_TIDNOTEXISTEXCEPTION_H

#include <exception>
#include <string>

class TIdNotExistException : std::exception {
    public:
    TIdNotExistException(unsigned id);

    public:
    virtual const char* what() const noexcept override;

    protected:
    std::string m_sMessage;
};


#endif //LAB_1_TIDNOTEXISTEXCEPTION_H
