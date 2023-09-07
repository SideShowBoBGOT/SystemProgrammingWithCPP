#include "TBook.h"

const std::string& TBook::Title() const {
	return m_sTitle;
}

void TBook::Title(const std::string& title) {
	m_sTitle = title;
}

const std::string& TBook::Author() const {
	return m_sAuthor;
}

void TBook::Author(const std::string& author) {
	m_sAuthor = author;
}
