#include <sstream>
#include "TInvalidIdException.h"

TInvalidIdException::TInvalidIdException(int id) {
    std::stringstream s;
    s << "Id is less than zero: " << id;

}
