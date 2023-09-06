#ifndef LAB_1_TLIBRARY_H
#define LAB_1_TLIBRARY_H

#include <memory>
#include <expected>
#include <vector>
#include <format>
#include <algorithm>

class TUser;
class TWorker;

template<typename T>
concept UserDerivable = std::is_base_of_v<TUser, T>;

class TLibrary {
	public:
	TLibrary()=default;
	virtual ~TLibrary()=default;
	
	public:
	virtual const std::vector<std::shared_ptr<TWorker>>& Workers() const;
	virtual auto AddWorker(const std::shared_ptr<TWorker>& worker) -> std::expected<void, std::logic_error>;
	virtual auto RemoveWorker(unsigned id) -> std::expected<void, std::invalid_argument>;
	
	public:
	virtual const std::vector<std::shared_ptr<TUser>>& Users() const;
	virtual auto AddUser(const std::shared_ptr<TUser>& user) -> std::expected<void, std::logic_error>;
	virtual auto RemoveUser(unsigned id) -> std::expected<void, std::invalid_argument>;
	
	protected:
	template<UserDerivable T>
	static auto FindById(const std::vector<std::shared_ptr<T>>& users, unsigned id) {
		return std::find_if(users.begin(), users.end(), [id](const auto& u) {
			return id==u->Id();
		});
	}
	
	template<UserDerivable T>
	static auto RemoveById(std::vector<std::shared_ptr<T>>& users, unsigned id)
		-> std::expected<void, std::invalid_argument> {
		
		const auto it = FindById(users, id);
		if(it==users.end()) {
			return std::unexpected(std::invalid_argument(std::format(R"(There is no id "{}")", id)));
		}
		
		users.erase(it);
	}
	
	template<UserDerivable T>
	static auto IsUniqueId(const std::vector<std::shared_ptr<T>>& users, unsigned id) {
		return FindById(users, id)==users.end();
	}
	
	template<UserDerivable T>
	static auto AddToContainer(std::vector<std::shared_ptr<T>>& users, const std::shared_ptr<T>& user) {
		if(!IsUniqueId(users, user->Id())) {
			return std::unexpected(std::logic_error(std::format(R"(Id "{}" is not unique)", user->Id())));
		}
		users.emplace_back(user);
	}
	
	protected:
	std::vector<std::shared_ptr<TWorker>> m_vWorkers;
	std::vector<std::shared_ptr<TUser>> m_vUsers;
};


#endif //LAB_1_TLIBRARY_H
