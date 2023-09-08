#ifndef LAB_1_TCUSTOMCLI_H
#define LAB_1_TCUSTOMCLI_H

#include <string>
#include <memory>

namespace CLI {
	class App;
}

class TLibrary;

class TCustomCLI {
	public:
	TCustomCLI();
	virtual ~TCustomCLI()=default;
	
	public:
	void Execute();

	protected:
	CLI::App* DecorateAddCommandWithCommonOptions(const std::string& suffix);
	
	protected:
	std::unique_ptr<CLI::App> m_pApp;
	std::unique_ptr<TLibrary> m_pLibrary;
};


#endif //LAB_1_TCUSTOMCLI_H
