#ifndef LAB_1_TINVALIDIDEXCEPTION_H
#define LAB_1_TINVALIDIDEXCEPTION_H


#include <iostream>

class TInvalidIdException : std::exception {
    public:
    TInvalidIdException(int id);

    protected:
    std::string m_sMessage

};


#endif //LAB_1_TINVALIDIDEXCEPTION_H
