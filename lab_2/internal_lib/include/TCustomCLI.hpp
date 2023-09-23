#ifndef LAB_1_TCUSTOMCLI_H
#define LAB_1_TCUSTOMCLI_H

#include <string>
#include <memory>
#include <iostream>

#include <CLI/CLI.hpp>

class TLibrary;

class TCustomCLI : public CLI::App {
	public:
	explicit TCustomCLI(const std::string& name);
	
	protected:
	CLI::App* DecorateAddUserWorker(const std::string& suffix);
	CLI::App* DecorateAddWorkerCommand();
	CLI::App* DecorateRemoveUserWorker(const std::string& suffix);
	CLI::App* DecorateAddBook();
	CLI::App* DecorateRemoveBook();
	CLI::App* DecorateBorrowReturnBook(const std::string& prefix);
	CLI::App* DecorateBorrowBook();
	CLI::App* DecorateReturnBook();
	CLI::App* DecorateShow(const std::string& suffix);
	
	protected:
	void AddUser();
	void AddWorker();
	void AddBook();
	unsigned RemoveCommon(const std::string& suffix);
	void RemoveUser();
	void RemoveWorker();
	void RemoveBook();
	std::pair<unsigned, unsigned> BorrowReturnBook(const std::string& prefix);
	void BorrowBook();
	void ReturnBook();
	
	template<class T>
	void ShowVector(const std::vector<std::shared_ptr<T>>& vv) {
		for(const auto& el : vv) {
			std::cout << *el << "\n";
		}
	}
	
	protected:
	std::shared_ptr<TLibrary> m_pLibrary;
};


#endif //LAB_1_TCUSTOMCLI_H
