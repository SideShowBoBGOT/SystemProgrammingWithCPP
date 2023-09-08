#ifndef LAB_1_TVARIADICNUMBEREXCEPTION_H
#define LAB_1_TVARIADICNUMBEREXCEPTION_H

#include <exception>
#include <format>

#include "../Helpers/SStringLiteral.h"
#include "../Helpers/SVariadicElementsString.h"

template<SStringLiteral Literal>
class TVariadicNumberException : public std::exception {
	public:
	template<typename Id, typename ...Ids>
    explicit TVariadicNumberException(Id id, Ids... ids) {
    	m_sMessage = (std::format(Literal.Value, SVariadicElementsString<Id, Ids...>()(id, ids...)));
    }
    virtual ~TVariadicNumberException()=default;

    public:
    virtual const char* what() const noexcept override {
    	return m_sMessage.c_str();
    }
	
    protected:
    std::string m_sMessage;
};

using TIdNotUniqueException = TVariadicNumberException<R"(Id ({}) is not unique)">;
using TIdNotExistException = TVariadicNumberException<R"(Id ({}) does not exist)">;
using TForeignIdException = TVariadicNumberException<R"(Foreign reference to Id ({}) exists)">;

#endif //LAB_1_TVARIADICNUMBEREXCEPTION_H