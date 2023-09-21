#include <iostream>
#include <fstream>

#include "../include/TLibrary.h"
#include "../include/TWorker.h"
#include "../include/TBook.h"
#include "../include/TUserBook.h"

static const std::string s_sUsersFile = "users.txt";
static const std::string s_sWorkersFile = "workers.txt";
static const std::string s_sBooksFile = "books.txt";
static const std::string s_sBorrowedBooksFile = "borrowed_books.txt";

TLibrary::TLibrary() {
	LoadState(m_vUsers, s_sUsersFile);
	LoadState(m_vWorkers, s_sWorkersFile);
	LoadState(m_vBooks, s_sBooksFile);
	LoadState(m_vUserBooks, s_sBorrowedBooksFile);
}

TLibrary::~TLibrary() {
	SaveState(m_vUsers, s_sUsersFile);
	SaveState(m_vWorkers, s_sWorkersFile);
	SaveState(m_vBooks, s_sBooksFile);
	SaveState(m_vUserBooks, s_sBorrowedBooksFile);
}

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
	
	const auto userIt = std::find_if(m_vUserBooks.begin(), m_vUserBooks.end(),
									 [id](const auto& el) {
			return el->UserId()==id;
		}
	);
	if(userIt != m_vUserBooks.end()) {
		return std::unexpected(TForeignIdException({(*userIt)->UserId()}));
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
	
	const auto userIt = std::find_if(m_vUserBooks.begin(), m_vUserBooks.end(),
									 [id](const auto& el) {
			return el->BookId()==id;
		}
	);
	if(userIt != m_vUserBooks.end()) {
		return std::unexpected(TForeignIdException({(*userIt)->UserId()}));
	}
    
    return RemoveById(m_vBooks, id);
}

const std::vector<std::shared_ptr<TUserBook>>& TLibrary::UserBooks() const {
	return m_vUserBooks;
}

auto TLibrary::BorrowBook(unsigned bookId, unsigned userId)
    -> std::expected<std::monostate, std::variant<TIdNotExistException, TIdNotUniqueException>> {
    
	if(!IsContainId(m_vBooks, bookId)) {
		return std::unexpected(TIdNotExistException({bookId}));
	}
	if(!IsContainId(m_vUsers, userId)) {
		return std::unexpected(TIdNotExistException({userId}));
	}
	if(FindUserBook(userId, bookId) != m_vUserBooks.end()) {
		return std::unexpected(TIdNotUniqueException({userId, bookId}));
	}
	
	m_vUserBooks.emplace_back(std::make_shared<TUserBook>(userId, bookId));
	
	return std::monostate();
}

auto TLibrary::ReturnBook(unsigned int bookId, unsigned int userId)
    -> std::expected<std::monostate, TIdNotExistException> {
    
    const auto it = FindUserBook(userId, bookId);
    
    if(it == m_vUserBooks.end()) {
		return std::unexpected(TIdNotExistException({userId, bookId}));
    }
	
	m_vUserBooks.erase(it);
	
	return std::monostate();
}

std::vector<std::shared_ptr<TUserBook>>::iterator TLibrary::FindUserBook(unsigned int userId, unsigned int bookId) {
	const auto userBook = TUserBook(userId, bookId);
	return std::find_if(m_vUserBooks.begin(), m_vUserBooks.end(),
						[&userBook](const auto& ub) {
			return *ub==userBook;
    	}
    );
}
