#include <format>

#include "TIdException.h"
#include "../Helpers/NNHelperFuncs.h"

#define NUMBER_ERROR(className, message) \
	className::className(const std::vector<unsigned>& ids) {\
    	m_sMessage = std::format(message, NNHelperFuncs::VectorString(ids));\
	}\
	const char* className::what() const noexcept {\
		return m_sMessage.c_str();\
	}\

NUMBER_ERROR(TIdNotUniqueException, "Id ({}) is not unique");
NUMBER_ERROR(TIdNotExistException, "Id ({}) does not exist");
NUMBER_ERROR(TForeignIdException, "Foreign reference to Id ({}) exists");

#undef NUMBER_ERROR