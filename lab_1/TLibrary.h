#ifndef LAB_1_TLIBRARY_H
#define LAB_1_TLIBRARY_H

#include <memory>
#include <vector>
#include <algorithm>

class TUser;
class TWorker;

class TLibrary {
	public:
	TLibrary()=default;
	virtual ~TLibrary()=default;
	
	public:
	virtual const std::vector<std::shared_ptr<TWorker>>& Workers() const;
	virtual void AddWorker(const std::shared_ptr<TWorker>& worker);
	virtual void RemoveWorker(unsigned id);
	
	public:
	virtual const std::vector<std::shared_ptr<TUser>>& Users() const;
	virtual void AddUser(const std::shared_ptr<TUser>& worker);
	virtual void RemoveUser(unsigned id);
	
	protected:
	template<typename T> requires std::is_base_of_v<TUser, T>
	bool IsUniqueId(const std::vector<std::shared_ptr<T>>& users, const std::shared_ptr<T>& user) {
		const auto it = std::find_if(users.begin(), users.end(), [user](const auto& u) {
			return user->Id()==u->Id();
		});
		return it==users.end();
	}
	
	protected:
	std::vector<std::shared_ptr<TWorker>> m_vWorkers;
	std::vector<std::shared_ptr<TUser>> m_vUsers;
};


#endif //LAB_1_TLIBRARY_H
