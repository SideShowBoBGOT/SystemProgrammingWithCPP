#include <format>

#include "CLI/CLI.hpp"
#include "TCustomCLI.h"

#include "../Helpers/NNHelperFuncs.h"
#include "../Models/EGender.h"
#include "../Models/TUser.h"
#include "../Models/TWorker.h"
#include "../Error/TAgeTooSmallException.h"
#include "../Controllers/TLibrary.h"

TCustomCLI::TCustomCLI() {
	m_pApp = std::make_unique<CLI::App>();
	m_pLibrary = std::make_unique<TLibrary>();
	
	auto addUserCommand = DecorateAddCommandWithCommonOptions("user");
	auto addWorkerCommand = DecorateAddCommandWithCommonOptions("worker");
	
	addWorkerCommand
		->add_option("--position-id,-pi")
		->description("worker's position id")
		->required(true);
	
	addUserCommand->parse_complete_callback([this, addUserCommand](){
		auto user = std::make_shared<TUser>();
		user->Name(addUserCommand->get_option("--name")->as<std::string>());
		user->MiddleName(addUserCommand->get_option("--middle-name")->as<std::string>());
		user->Surname(addUserCommand->get_option("--surname")->as<std::string>());
		user->Gender(addUserCommand->get_option("--gender")->as<EGender>());
		user->Residence(addUserCommand->get_option("--residence")->as<std::string>());
		user->Age(addUserCommand->get_option("--age")->as<unsigned>()).value();
		user->PassportData(addUserCommand->get_option("--passportData")->as<std::string>());
		m_pLibrary->AddUser(user).value();
	});
	
	addWorkerCommand->parse_complete_callback([this, addWorkerCommand]() {
		auto worker = std::make_shared<TWorker>();
		worker->Name(addWorkerCommand->get_option("--name")->as<std::string>());
		worker->MiddleName(addWorkerCommand->get_option("--middle-name")->as<std::string>());
		worker->Surname(addWorkerCommand->get_option("--surname")->as<std::string>());
		worker->Gender(addWorkerCommand->get_option("--gender")->as<EGender>());
		worker->Residence(addWorkerCommand->get_option("--residence")->as<std::string>());
		worker->Age(addWorkerCommand->get_option("--age")->as<unsigned>()).value();
		worker->PassportData(addWorkerCommand->get_option("--passportData")->as<std::string>());
		worker->PositionId(addWorkerCommand->get_option("--position-id")->as<unsigned >());
		m_pLibrary->AddWorker(worker).value();
	});
}

void TCustomCLI::Execute() {

}

CLI::App* TCustomCLI::DecorateAddCommandWithCommonOptions(const std::string& suffix) {
	auto subcommand = m_pApp->add_subcommand("add-" + suffix);
	const auto name = subcommand
		->add_option("--name,-n")
		->description(std::format(R"({}'s name)", suffix))
		->required(true);
	const auto middleName = subcommand
		->add_option("--middle-name,-m")
		->description(std::format(R"({}'s middle name)", suffix))
		->required(true);
	const auto surname = subcommand
		->add_option("--surname,-s")
		->description(std::format(R"({}'s surname)", suffix))
		->required(true);
	const auto gender = subcommand
		->add_option("--gender,-g")
		->description(std::format(R"({}'s gender)", suffix))
		->required(true)
		->transform(
			CLI::CheckedTransformer(
				NNHelperFuncs::EnumMapStringValue<EGender>(),
				CLI::ignore_case
			)
		);
	const auto residence = subcommand
		->add_option("--residence,-r")
		->description(std::format(R"({}'s residence)", suffix))
		->required(true);
	const auto age = subcommand
		->add_option("--age,-a")
		->description(std::format(R"({}'s age)", suffix))
		->required(true)
		->check(CLI::PositiveNumber);
	const auto passportData = subcommand
		->add_option("--passport-data,-pd")
		->description(std::format(R"({}'s passport data)", suffix))
		->required(true);
	
	return subcommand;
}


