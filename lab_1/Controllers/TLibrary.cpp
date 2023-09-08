#include "TLibrary.h"
#include "../Models/TWorker.h"
#include "../Models/TBook.h"

const std::vector<std::shared_ptr<TWorker>>& TLibrary::Workers() const {
	return m_vWorkers;
}

auto TLibrary::AddWorker(const std::shared_ptr<TWorker>& worker) -> std::expected<std::monostate, TIdNotUniqueException> {
	return AddToContainer(m_vWorkers, worker);
}

auto TLibrary::RemoveWorker(unsigned int id) -> std::expected<std::monostate, TIdNotExistException> {
	return RemoveById(m_vWorkers, id);
}

const std::vector<std::shared_ptr<TUser>>& TLibrary::Users() const {
	return m_vUsers;
}

auto TLibrary::AddUser(const std::shared_ptr<TUser>& user) -> std::expected<std::monostate, TIdNotUniqueException> {
	return AddToContainer(m_vUsers, user);
}

auto TLibrary::RemoveUser(unsigned id)
	-> std::expected<std::monostate, std::variant<TIdNotExistException, TForeignIdException>> {
	
	const auto userIt = std::find_if(m_vBorrowedBooks.begin(), m_vBorrowedBooks.end(),
		[id](const auto& el) {
			return el.UserId==id;
		}
	);
	if(userIt!=m_vBorrowedBooks.end()) {
		return std::unexpected(TForeignIdException(userIt->UserId));
	}
	return RemoveById(m_vUsers, id);;
}

const std::vector<std::shared_ptr<TBook>> &TLibrary::Books() const {
    return m_vBooks;
}

auto TLibrary::AddBook(const std::shared_ptr<TBook> &book) -> std::expected<std::monostate, TIdNotUniqueException> {
    return AddToContainer(m_vBooks, book);
}

auto TLibrary::RemoveBook(unsigned id)
	-> std::expected<std::monostate, std::variant<TIdNotExistException, TForeignIdException>> {
	
	const auto userIt = std::find_if(m_vBorrowedBooks.begin(), m_vBorrowedBooks.end(),
		[id](const auto& el) {
			return el.BookId==id;
		}
	);
	if(userIt!=m_vBorrowedBooks.end()) {
		return std::unexpected(TForeignIdException(userIt->BookId));
	}
    
    return RemoveById(m_vBooks, id);
}

std::vector<std::shared_ptr<TBook>> TLibrary::AvailableBooks() const {
	auto vv = std::vector<std::shared_ptr<TBook>>();
	std::copy_if(m_vBooks.begin(), m_vBooks.end(), std::back_inserter(vv), [this](const auto& book) {
		return std::find_if(m_vBorrowedBooks.begin(), m_vBorrowedBooks.end(), [&book](const auto& p) {
			return p.BookId == book->Id();
		}) == m_vBorrowedBooks.end();
	});
    return vv;
}

auto TLibrary::BorrowBook(unsigned bookId, unsigned userId)
    -> std::expected<std::monostate, std::variant<TIdNotExistException, TIdNotUniqueException>> {
    
	if(!IsContainId(m_vBooks, bookId)) {
		return std::unexpected(TIdNotExistException(bookId));
	}
	if(!IsContainId(m_vUsers, userId)) {
		return std::unexpected(TIdNotExistException(userId));
	}
	if(IsContain(m_vBorrowedBooks, SUserBook{userId, bookId})) {
		return std::unexpected(TIdNotUniqueException(bookId, userId));
	}
	
	m_vBorrowedBooks.emplace_back(bookId, userId);
	
	return std::monostate();
}

auto TLibrary::ReturnBook(unsigned int bookId, unsigned int userId)
    -> std::expected<std::monostate, TIdNotExistException> {
    
    const auto it = std::find(m_vBorrowedBooks.begin(), m_vBorrowedBooks.end(), SUserBook{userId, bookId});
    
    if(it==m_vBorrowedBooks.end()) {
		return std::unexpected(TIdNotExistException(userId, bookId));
    }
	
	m_vBorrowedBooks.erase(it);
	
	return std::monostate();
}

TLibrary::SUserBook::SUserBook(unsigned userId, unsigned bookId)
	: UserId{userId}, BookId{bookId} {}

bool TLibrary::SUserBook::operator==(const TLibrary::SUserBook& other) const {
	return UserId==other.UserId && BookId==other.BookId;
}
