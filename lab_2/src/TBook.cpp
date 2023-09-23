#include <TBook.hpp>

const std::string& TBook::Title() const {
	return m_sTitle;
}

void TBook::Title(const std::string& title) {
	m_sTitle = title;
}

std::ostream& operator<<(std::ostream& out, const TBook& book) {
	return book.Print(out);
}

std::ostream& TBook::Print(std::ostream& out) const {
	auto& mout = TIdMixin::Print(out);
	#define AA(xx) mout << "\t"#xx": " << xx() << ", ";
		AA(Title);
	#undef AA
	return mout;
}
