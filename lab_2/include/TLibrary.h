#ifndef LAB_1_TLIBRARY_H
#define LAB_1_TLIBRARY_H

#include <memory>
#include <expected>
#include <vector>
#include <format>
#include <algorithm>
#include <filesystem>

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/shared_ptr.hpp>

#include "TIdException.h"

class TIdMixin;
class TUser;
class TWorker;
class TBook;
class TUserBook;

template<typename T>
concept CIdMixin = std::is_base_of_v<TIdMixin, T>;

class TLibrary {
	public:
	TLibrary();
	virtual ~TLibrary();
	
	public:
	virtual const std::vector<std::shared_ptr<TWorker>>& Workers() const;
	virtual auto AddWorker(const std::shared_ptr<TWorker>& worker)
		-> std::expected<std::monostate, TIdNotUniqueException>;
	virtual auto RemoveWorker(unsigned id)
		-> std::expected<std::monostate, TIdNotExistException>;
	
	public:
	virtual const std::vector<std::shared_ptr<TUser>>& Users() const;
	virtual auto AddUser(const std::shared_ptr<TUser>& user)
		-> std::expected<std::monostate, TIdNotUniqueException>;
	virtual auto RemoveUser(unsigned id)
		-> std::expected<std::monostate, std::variant<TIdNotExistException, TForeignIdException>>;

    public:
    virtual const std::vector<std::shared_ptr<TBook>>& Books() const;
    virtual auto AddBook(const std::shared_ptr<TBook>& book)
    	-> std::expected<std::monostate, TIdNotUniqueException>;
    virtual auto RemoveBook(unsigned id)
    	-> std::expected<std::monostate, std::variant<TIdNotExistException, TForeignIdException>>;

    public:
    virtual const std::vector<std::shared_ptr<TUserBook>>& UserBooks() const;
    virtual auto BorrowBook(unsigned bookId, unsigned userId)
    	-> std::expected<std::monostate, std::variant<TIdNotExistException, TIdNotUniqueException>>;
	virtual auto ReturnBook(unsigned bookId, unsigned userId) -> std::expected<std::monostate, TIdNotExistException>;

	protected:
	template<typename T>
	static void SaveState(const T& vv, const std::string& fileName) {
		std::ofstream outFile(fileName);
		boost::archive::text_oarchive outArchive(outFile);
		outArchive << vv;
	};
	
	template<typename T>
	static void LoadState(T& vv, const std::string& fileName) {
		std::ifstream inFile(fileName);
		if(inFile) {
			boost::archive::text_iarchive inArchive(inFile);
			inArchive >> vv;
		}
	}

	protected:
	template<CIdMixin T>
	static auto FindById(const std::vector<std::shared_ptr<T>>& cont, unsigned id) {
		return std::find_if(cont.begin(), cont.end(), [id](const auto& u) {
			return id==u->Id();
		});
	}

	template<CIdMixin T>
	static auto RemoveById(std::vector<std::shared_ptr<T>>& cont, unsigned id)
		-> std::expected<std::monostate, TIdNotExistException> {
		const auto it = FindById(cont, id);
		if(it==cont.end()) {
			return std::unexpected(TIdNotExistException({id}));
		}
		cont.erase(it);
		return std::monostate();
	}
	
	template<CIdMixin T>
	static auto IsContainId(const std::vector<std::shared_ptr<T>>& cont, unsigned id) {
		return FindById(cont, id)!=cont.end();
	}
	
	template<CIdMixin T>
	static auto AddToContainer(std::vector<std::shared_ptr<T>>& cont, const std::shared_ptr<T>& el)
		-> std::expected<std::monostate, TIdNotUniqueException> {
		
		if(IsContainId(cont, el->Id())) {
			return std::unexpected(TIdNotUniqueException({el->Id()}));
		}
		cont.emplace_back(el);
		return std::monostate();
	}
	
	template<typename T>
	static bool IsContain(const std::vector<T>& cont, const T& el) {
		return std::find(cont.begin(), cont.end(), el)!=cont.end();
	}
	
	protected:
	std::vector<std::shared_ptr<TUserBook>>::iterator FindUserBook(unsigned userId, unsigned bookId);
	
	protected:
	std::vector<std::shared_ptr<TWorker>> m_vWorkers;
	std::vector<std::shared_ptr<TUser>> m_vUsers;
	std::vector<std::shared_ptr<TBook>> m_vBooks;
	std::vector<std::shared_ptr<TUserBook>> m_vUserBooks;
};


#endif //LAB_1_TLIBRARY_H
