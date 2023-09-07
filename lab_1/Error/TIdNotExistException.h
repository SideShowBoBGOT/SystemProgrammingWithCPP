#ifndef LAB_1_TIDNOTEXISTEXCEPTION_H
#define LAB_1_TIDNOTEXISTEXCEPTION_H

#include <exception>

class TIdNotExistException : std::exception {
    public:
    TIdNotExistException(unsigned id);
    virtual ~TIdNotExistException()=default;

    public:
    virtual const char* what() const noexcept override;
};


#endif //LAB_1_TIDNOTEXISTEXCEPTION_H
