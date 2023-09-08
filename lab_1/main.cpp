#include <CLI/CLI.hpp>
#include <iostream>
#include <string>

#include "Models/EGender.h"
#include "Helpers/NNHelperFuncs.h"
#include "Models/TWorker.h"

int main(int argc, char **argv) {
    CLI::App app{"Lab1"};
	
	auto subcommand = app.add_subcommand("add-worker");
	
	auto name = std::string();
	
	auto optName = subcommand
		->add_option("--name,-n", name)
		->required(true);
		
	auto middleName = std::string();
	subcommand
		->add_option("--middle-name,-m", middleName)
		->required(true);
		
	auto surname = std::string();
	subcommand
		->add_option("--surname,-s", surname)
		->required(true);
		
	auto gender = EGender::Male;
	subcommand
		->add_option("--gender,-g", gender)
		->required(true)
		->transform(
			CLI::CheckedTransformer(
				NNHelperFuncs::EnumMapStringValue<EGender>(),
				CLI::ignore_case
			)
		);
	
	auto residence = std::string();
	subcommand
		->add_option("--residence,-r", residence)
		->required(true);
	
	auto age = 0u;
	subcommand
		->add_option("--age,-a",age)
		->required(true)
		->check(CLI::PositiveNumber);
		
	auto passportData = std::string();
	subcommand
		->add_option("--passport-data,-p", passportData)
		->required(true);
	
	subcommand->parse_complete_callback([subcommand]() {
		std::cout<< subcommand->get_option("--name")->as<std::string>()<<std::endl;
	});
	

    CLI11_PARSE(app);
    
    subcommand->call;
    
    return 0;
}