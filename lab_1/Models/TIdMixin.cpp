#include "TIdMixin.h"

unsigned int TIdMixin::Id() const {
    return 0;
}

void TIdMixin::Id(unsigned id) {
	m_uId = id;
}