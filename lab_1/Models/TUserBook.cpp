#include "TUserBook.h"

TUserBook::TUserBook(unsigned userId, unsigned bookId)
	: m_uUserId{userId}, m_uBookId{bookId} {}

bool TUserBook::operator==(const TUserBook& other) const {
	return UserId()==other.UserId() && BookId()==other.BookId();
}

unsigned TUserBook::UserId() const {
	return m_uUserId;
}

void TUserBook::UserId(unsigned userId) {
	m_uUserId = userId;
}

unsigned TUserBook::BookId() const {
	return m_uBookId;
}

void TUserBook::BookId(unsigned bookId) {
	m_uBookId = bookId;
}

std::ostream& operator<<(std::ostream& out, const TUserBook& userBook) {
	return userBook.Print(out);
}

std::ostream& TUserBook::Print(std::ostream& out) const {
	out << "UserId: " << UserId() << ", ";
	#define AA(xx) out << "\t"#xx": " << xx() << ", ";
		AA(BookId)
	#undef AA
	return out;
}
