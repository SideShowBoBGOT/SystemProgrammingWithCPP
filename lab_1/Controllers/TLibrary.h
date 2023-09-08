#ifndef LAB_1_TLIBRARY_H
#define LAB_1_TLIBRARY_H

#include <memory>
#include <expected>
#include <vector>
#include <format>
#include <algorithm>
#include "../Error/TVariadicNumberException.h"

class TIdMixin;
class TUser;
class TWorker;
class TBook;

template<typename T>
concept CIdMixin = std::is_base_of_v<TIdMixin, T>;

class TLibrary {
	public:
	TLibrary()=default;
	virtual ~TLibrary()=default;
	
	public:
	virtual const std::vector<std::shared_ptr<TWorker>>& Workers() const;
	virtual auto AddWorker(const std::shared_ptr<TWorker>& worker) -> std::expected<void, TIdNotUniqueException>;
	virtual auto RemoveWorker(unsigned id) -> std::expected<void, TIdNotExistException>;
	
	public:
	virtual const std::vector<std::shared_ptr<TUser>>& Users() const;
	virtual auto AddUser(const std::shared_ptr<TUser>& user) -> std::expected<void, TIdNotUniqueException>;
	virtual auto RemoveUser(unsigned id) -> std::expected<void, std::variant<TIdNotExistException, TForeignIdException>>;

    public:
    virtual const std::vector<std::shared_ptr<TBook>>& Books() const;
    virtual auto AddBook(const std::shared_ptr<TBook>& book) -> std::expected<void, TIdNotUniqueException>;
    virtual auto RemoveBook(unsigned id) -> std::expected<void, std::variant<TIdNotExistException, TForeignIdException>>;

    public:
    virtual std::vector<std::shared_ptr<TBook>> AvailableBooks() const;
    virtual auto BorrowBook(unsigned bookId, unsigned userId)
    	-> std::expected<void, std::variant<TIdNotExistException, TIdNotUniqueException>>;
	virtual auto ReturnBook(unsigned bookId, unsigned userId) -> std::expected<void, TIdNotExistException>;

	protected:
	template<CIdMixin T>
	static auto FindById(const std::vector<std::shared_ptr<T>>& cont, unsigned id) {
		return std::find_if(cont.begin(), cont.end(), [id](const auto& u) {
			return id==u->Id();
		});
	}

	template<CIdMixin T>
	static auto RemoveById(std::vector<std::shared_ptr<T>>& cont, unsigned id) {
		const auto it = FindById(cont, id);
		if(it==cont.end()) {
			return std::unexpected(TIdNotExistException(id));
		}
		cont.erase(it);
	}
	
	template<CIdMixin T>
	static auto IsContainId(const std::vector<std::shared_ptr<T>>& cont, unsigned id) {
		return FindById(cont, id)!=cont.end();
	}
	
	template<CIdMixin T>
	static auto AddToContainer(std::vector<std::shared_ptr<T>>& cont, const std::shared_ptr<T>& el) {
		if(IsContainId(cont, el->Id())) {
			return std::unexpected(TIdNotUniqueException(el->Id()));
		}
		cont.emplace_back(el);
	}
	
	template<typename T>
	bool IsContain(const std::vector<T>& cont, const T& el) {
		return std::find(cont.begin(), cont.end(), el)!=cont.end();
	}
	
	protected:
	std::vector<std::shared_ptr<TWorker>> m_vWorkers;
	std::vector<std::shared_ptr<TUser>> m_vUsers;
	std::vector<std::shared_ptr<TBook>> m_vBooks;
	
	struct SUserBook {
		explicit SUserBook(unsigned userId, unsigned bookId);
		bool operator==(const SUserBook& other) const;
		unsigned UserId = 0;
		unsigned BookId = 0;
	};
	std::vector<SUserBook> m_vBorrowedBooks;
};


#endif //LAB_1_TLIBRARY_H
