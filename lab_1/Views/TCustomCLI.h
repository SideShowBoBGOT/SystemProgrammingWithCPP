#ifndef LAB_1_TCUSTOMCLI_H
#define LAB_1_TCUSTOMCLI_H

#include <string>
#include <memory>

#include "CLI/CLI.hpp"

class TLibrary;

class TCustomCLI : public CLI::App {
	public:
	explicit TCustomCLI(const std::string& name);
	
	protected:
	CLI::App* DecorateAddCommandWithCommonOptions(const std::string& suffix);
	
	protected:
	std::shared_ptr<TLibrary> m_pLibrary;
};


#endif //LAB_1_TCUSTOMCLI_H
