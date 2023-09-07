#ifndef LAB_1_TGENDERNONEEXCEPTION_H
#define LAB_1_TGENDERNONEEXCEPTION_H

#include <exception>

class TGenderNoneException : std::exception {
    public:
    TGenderNoneException()=default;

    public:
    virtual const char* what() const noexcept override;
};


#endif //LAB_1_TGENDERNONEEXCEPTION_H
