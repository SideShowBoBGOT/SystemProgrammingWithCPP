#ifndef LAB_1_TIDEXCEPTION_H
#define LAB_1_TIDEXCEPTION_H

#include <exception>
#include <vector>
#include <string>

#define NUMBER_ERROR(className) \
class className : public std::exception {\
	public:\
    explicit className(const std::vector<unsigned>& ids);\
    virtual ~className()=default;\
    virtual const char* what() const noexcept override;\
    protected:\
    std::string m_sMessage;\
};\

NUMBER_ERROR(TIdNotUniqueException);
NUMBER_ERROR(TIdNotExistException);
NUMBER_ERROR(TForeignIdException);

#undef NUMBER_ERROR



#endif //LAB_1_TIDEXCEPTION_H
