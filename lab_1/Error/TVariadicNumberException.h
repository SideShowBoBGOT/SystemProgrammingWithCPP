#ifndef LAB_1_TVARIADICNUMBEREXCEPTION_H
#define LAB_1_TVARIADICNUMBEREXCEPTION_H

#include <exception>
#include <format>

#include "../Helpers/TStringLiteral.h"
#include "../Helpers/SVariadicElementsString.h"

template<TStringLiteral Literal>
class TVariadicNumberException : public std::exception {
	public:
	template<typename Id, typename ...Ids>
    explicit TVariadicNumberException(Id id, Ids... ids) {
    	m_sMessage = (std::format(Literal.Value, SVariadicElementsString<Id, Ids...>()(id, ids...)));
    }

    public:
    virtual const char* what() const noexcept override {
    	return m_sMessage.c_str();
    }
	
    protected:
    std::string m_sMessage;
};

using TIdNotUniqueException = TVariadicNumberException<R"(Id ({}) is not unique)">;
using TIdNotExistException = TVariadicNumberException<R"(Id ({}) does not exist)">;

#endif //LAB_1_TVARIADICNUMBEREXCEPTION_H
