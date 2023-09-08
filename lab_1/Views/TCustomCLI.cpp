#include <format>


#include "TCustomCLI.h"

#include "../Helpers/NNHelperFuncs.h"
#include "../Models/EGender.h"
#include "../Models/TUser.h"
#include "../Models/TWorker.h"
#include "../Error/TAgeTooSmallException.h"
#include "../Controllers/TLibrary.h"
#include "../Models/TBook.h"

TCustomCLI::TCustomCLI(const std::string& name)
	: CLI::App(name) {
	
	m_pLibrary = std::make_shared<TLibrary>();
	
	DecorateAddUserWorker("user")->parse_complete_callback([this](){ AddUser(); });
	DecorateAddWorkerCommand()->parse_complete_callback([this]() { AddWorker(); });
	DecorateAddBook()->parse_complete_callback([this]() { AddBook(); });
	DecorateRemoveUserWorker("user")->parse_complete_callback([this](){ RemoveUser(); });
	DecorateRemoveUserWorker("worker")->parse_complete_callback([this](){ RemoveWorker(); });
	DecorateRemoveBook()->parse_complete_callback([this]() { RemoveBook(); });
	DecorateBorrowBook()->parse_complete_callback([this]() { BorrowBook(); });
	DecorateReturnBook()->parse_complete_callback([this]() { ReturnBook(); });
}

CLI::App* TCustomCLI::DecorateAddUserWorker(const std::string& suffix) {
	auto subcommand = add_subcommand("add-" + suffix, std::format("Add {}", suffix));
	const auto titled = NNHelperFuncs::TitledString(suffix);
	const auto id = subcommand
		->add_option("--id,-i")
		->description(std::format(R"({}'s id)", titled))
		->required(true);
	const auto name = subcommand
		->add_option("--name,-n")
		->description(std::format(R"({}'s name)", titled))
		->required(true);
	const auto middleName = subcommand
		->add_option("--middle-name,-m")
		->description(std::format(R"({}'s middle name)", titled))
		->required(true);
	const auto surname = subcommand
		->add_option("--surname,-s")
		->description(std::format(R"({}'s surname)", titled))
		->required(true);
	const auto gender = subcommand
		->add_option("--gender,-g")
		->description(std::format(R"({}'s gender)", titled))
		->required(true)
		->transform(
			CLI::CheckedTransformer(
				NNHelperFuncs::EnumMapStringValue<EGender>(),
				CLI::ignore_case
			)
		);
	const auto residence = subcommand
		->add_option("--residence,-r")
		->description(std::format(R"({}'s residence)", titled))
		->required(true);
	const auto age = subcommand
		->add_option("--age,-a")
		->description(std::format(R"({}'s age)", titled))
		->required(true);
	const auto passportData = subcommand
		->add_option("--passport-data")
		->description(std::format(R"({}'s passport data)", titled))
		->required(true);
	
	return subcommand;
}

CLI::App* TCustomCLI::DecorateAddWorkerCommand() {
	auto addWorkerCommand = DecorateAddUserWorker("worker");
	
	addWorkerCommand
		->add_option("--position-id")
		->description("Worker's position id")
		->required(true);
	
	return addWorkerCommand;
}

CLI::App* TCustomCLI::DecorateRemoveUserWorker(const std::string& suffix) {
	auto removeWorker = add_subcommand("remove-" + suffix, std::format("Remove {}", suffix));
	const auto titled = NNHelperFuncs::TitledString(suffix);
	removeWorker
		->add_option("--id,-i")
		->description(std::format(R"({}'s id)", titled))
		->required(true);
	return removeWorker;
}

CLI::App* TCustomCLI::DecorateAddBook() {
	auto addBook = add_subcommand("add-book", "Add book");
	addBook
		->add_option("--id,-i")
		->description("Books's id")
		->required(true);
	addBook
		->add_option("--title,-t")
		->description("Books's title")
		->required(true);
	return addBook;
}

CLI::App* TCustomCLI::DecorateRemoveBook() {
	auto removeBook = add_subcommand("remove-book", "Remove book");
	removeBook
		->add_option("--id,-i")
		->description("Book's id")
		->required(true);
	return removeBook;
}

CLI::App* TCustomCLI::DecorateBorrowReturnBook(const std::string& prefix) {
	const auto titled = NNHelperFuncs::TitledString(prefix);
	auto cmd = add_subcommand(
		std::format("{}-book", prefix),
		std::format("{} book", titled)
	);
	cmd->add_option("--book-id,-b")
		->description("Book's id")
		->required(true);
	cmd->add_option("--user-id,-u")
		->description("User's id")
		->required(true);
	return cmd;
}

CLI::App* TCustomCLI::DecorateBorrowBook() {
	return DecorateBorrowReturnBook("borrow");
}

CLI::App* TCustomCLI::DecorateReturnBook() {
	return DecorateBorrowReturnBook("return");
}

void TCustomCLI::AddUser() {
	const auto cmd = this->get_subcommand("add-user");
	auto user = std::make_shared<TUser>();
	user->Id(cmd->get_option("--id")->as<unsigned>());
	user->Name(cmd->get_option("--name")->as<std::string>());
	user->MiddleName(cmd->get_option("--middle-name")->as<std::string>());
	user->Surname(cmd->get_option("--surname")->as<std::string>());
	user->Gender(cmd->get_option("--gender")->as<EGender>());
	user->Residence(cmd->get_option("--residence")->as<std::string>());
	user->Age(cmd->get_option("--age")->as<unsigned>()).value();
	user->PassportData(cmd->get_option("--passport-data")->as<std::string>());
	m_pLibrary->AddUser(user).value();
}

void TCustomCLI::AddWorker() {
	const auto cmd = this->get_subcommand("add-worker");
	auto worker = std::make_shared<TWorker>();
	worker->Id(cmd->get_option("--id")->as<unsigned >());
	worker->Name(cmd->get_option("--name")->as<std::string>());
	worker->MiddleName(cmd->get_option("--middle-name")->as<std::string>());
	worker->Surname(cmd->get_option("--surname")->as<std::string>());
	worker->Gender(cmd->get_option("--gender")->as<EGender>());
	worker->Residence(cmd->get_option("--residence")->as<std::string>());
	worker->Age(cmd->get_option("--age")->as<unsigned>()).value();
	worker->PassportData(cmd->get_option("--passport-data")->as<std::string>());
	worker->PositionId(cmd->get_option("--position-id")->as<unsigned >());
	m_pLibrary->AddWorker(worker).value();
}

void TCustomCLI::AddBook() {
	const auto cmd = this->get_subcommand("add-book");
	auto book = std::make_shared<TBook>();
	book->Id(cmd->get_option("--id")->as<unsigned >());
	book->Title(cmd->get_option("--title")->as<std::string>());
	m_pLibrary->AddBook(book).value();
}

unsigned TCustomCLI::RemoveCommon(const std::string& suffix) {
	const auto cmd = this->get_subcommand(std::format("remove-{}", suffix));
	const auto id = cmd->get_option("--id")->as<unsigned>();
	return id;
}

void TCustomCLI::RemoveUser() {
	const auto id = RemoveCommon("user");
	m_pLibrary->RemoveUser(id).value();
}

void TCustomCLI::RemoveWorker() {
	const auto id = RemoveCommon("worker");
	m_pLibrary->RemoveWorker(id).value();
}

void TCustomCLI::RemoveBook() {
	const auto id = RemoveCommon("book");
	m_pLibrary->RemoveBook(id).value();
}

std::pair<unsigned, unsigned> TCustomCLI::BorrowReturnBook(const std::string& prefix) {
	const auto cmd = this->get_subcommand(std::format("{}-book", prefix));
	const auto bookId = cmd->get_option("--book-id")->as<unsigned>();
	const auto userId = cmd->get_option("--user-id")->as<unsigned>();
	return {bookId, userId};
}

void TCustomCLI::BorrowBook() {
	const auto [bookId, userId] = BorrowReturnBook("borrow");
	m_pLibrary->BorrowBook(bookId, userId).value();
}

void TCustomCLI::ReturnBook() {
	const auto [bookId, userId] = BorrowReturnBook("return");
	m_pLibrary->BorrowBook(bookId, userId).value();
}




