#include "TLibrary.h"
#include "TWorker.h"
#include "TBook.h"

const std::vector<std::shared_ptr<TWorker>>& TLibrary::Workers() const {
	return m_vWorkers;
}

auto TLibrary::AddWorker(const std::shared_ptr<TWorker>& worker) -> std::expected<void, std::invalid_argument> {
	return AddToContainer(m_vWorkers, worker);
}

auto TLibrary::RemoveWorker(unsigned int id) -> std::expected<void, std::invalid_argument> {
	return RemoveById(m_vWorkers, id);
}

const std::vector<std::shared_ptr<TUser>>& TLibrary::Users() const {
	return m_vUsers;
}

auto TLibrary::AddUser(const std::shared_ptr<TUser>& user) -> std::expected<void, std::invalid_argument> {
	return AddToContainer(m_vUsers, user);
}

auto TLibrary::RemoveUser(unsigned int id) -> std::expected<void, std::invalid_argument> {
	return RemoveById(m_vUsers, id);;
}

const std::vector<std::shared_ptr<TBook>> &TLibrary::Books() const {
    return m_vBooks;
}

auto TLibrary::AddBook(const std::shared_ptr<TBook> &book) -> std::expected<void, std::invalid_argument> {
    return AddToContainer(m_vBooks, book);
}

auto TLibrary::RemoveBook(unsigned int id) -> std::expected<void, std::invalid_argument> {
    return RemoveById(m_vBooks, id);
}
