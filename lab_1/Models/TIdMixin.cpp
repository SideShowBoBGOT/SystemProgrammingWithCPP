#include "TIdMixin.h"

unsigned int TIdMixin::Id() const {
    return m_uId;
}

void TIdMixin::Id(unsigned id) {
	m_uId = id;
}