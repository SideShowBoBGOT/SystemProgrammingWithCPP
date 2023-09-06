#include "TLibrary.h"

#include "TWorker.h"

void TLibrary::AddWorker(const std::shared_ptr<TWorker>& worker) {

}

void TLibrary::RemoveWorker(unsigned int id) {

}

const std::vector<std::shared_ptr<TWorker>>& TLibrary::Workers() const {
	return m_vWorkers;
}

const std::vector<std::shared_ptr<TUser>>& TLibrary::Users() const {
	return m_vUsers;
}

void TLibrary::AddUser(const std::shared_ptr<TUser>& worker) {

}

void TLibrary::RemoveUser(unsigned int id) {

}
