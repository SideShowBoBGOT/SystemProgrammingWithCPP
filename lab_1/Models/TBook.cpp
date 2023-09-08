#include "TBook.h"

const std::string& TBook::Title() const {
	return m_sTitle;
}

void TBook::Title(const std::string& title) {
	m_sTitle = title;
}
