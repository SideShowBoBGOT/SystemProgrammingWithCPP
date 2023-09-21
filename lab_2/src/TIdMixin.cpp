#include "../include/TIdMixin.h"

unsigned int TIdMixin::Id() const {
    return m_uId;
}

void TIdMixin::Id(unsigned id) {
	m_uId = id;
}

std::ostream& TIdMixin::Print(std::ostream& out) const {
	out << "Id: " << Id() << ", ";
	return out;
}

std::ostream& operator<<(std::ostream& out, const TIdMixin& id) {
	return id.Print(out);
}
