#include "TLibrary.h"
#include "../Models/TWorker.h"
#include "../Models/TBook.h"

const std::vector<std::shared_ptr<TWorker>>& TLibrary::Workers() const {
	return m_vWorkers;
}

auto TLibrary::AddWorker(const std::shared_ptr<TWorker>& worker) -> std::expected<void, TIdNotUniqueException> {
	return AddToContainer(m_vWorkers, worker);
}

auto TLibrary::RemoveWorker(unsigned int id) -> std::expected<void, TIdNotExistException> {
	return RemoveById(m_vWorkers, id);
}

const std::vector<std::shared_ptr<TUser>>& TLibrary::Users() const {
	return m_vUsers;
}

auto TLibrary::AddUser(const std::shared_ptr<TUser>& user) -> std::expected<void, TIdNotUniqueException> {
	return AddToContainer(m_vUsers, user);
}

auto TLibrary::RemoveUser(unsigned int id) -> std::expected<void, TIdNotExistException> {
	return RemoveById(m_vUsers, id);;
}

const std::vector<std::shared_ptr<TBook>> &TLibrary::Books() const {
    return m_vBooks;
}

auto TLibrary::AddBook(const std::shared_ptr<TBook> &book) -> std::expected<void, TIdNotUniqueException> {
    return AddToContainer(m_vBooks, book);
}

auto TLibrary::RemoveBook(unsigned int id) -> std::expected<void, TIdNotExistException> {
    return RemoveById(m_vBooks, id);
}

std::vector<std::shared_ptr<TBook>> TLibrary::AvailableBooks() const {
	auto vv = std::vector<std::shared_ptr<TBook>>();
	std::copy_if(vv.begin(), vv.end(), std::back_inserter(vv), [this](const auto& el) {
		return std::find_if(m_vBorrowedBooks.begin(), m_vBorrowedBooks.end(), [bookId=el->Id()](const auto& p) {
			return p.first == bookId;
		}) == m_vBorrowedBooks.end();
	});
    return vv;
}

auto TLibrary::BorrowBook(unsigned bookId, unsigned userId)
    -> std::expected<void, std::variant<TIdNotExistException, TIdNotUniqueException>> {
    
	if(!IsContainId(m_vBooks, bookId)) {
		return std::unexpected(TIdNotExistException(bookId));
	}
	if(!IsContainId(m_vUsers, userId)) {
		return std::unexpected(TIdNotExistException(userId));
	}
	if(IsContain(m_vBorrowedBooks, {bookId, userId})) {
		return std::unexpected(TIdNotUniqueException(bookId, userId));
	}
	
	m_vBorrowedBooks.emplace_back(bookId, userId);
}

auto TLibrary::ReturnBook(unsigned int bookId, unsigned int userId)
    -> std::expected<void, TIdNotExistException> {
    
    const auto ids = std::make_pair(bookId, userId);
    const auto it = std::find(m_vBorrowedBooks.begin(), m_vBorrowedBooks.end(), ids);
    
    if(it==m_vBorrowedBooks.end()) {
		return std::unexpected(TIdNotExistException(bookId, userId));
    }
	
	m_vBorrowedBooks.erase(it);
}