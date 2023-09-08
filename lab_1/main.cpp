#include <CLI/CLI.hpp>
#include <magic_enum.hpp>
#include <iostream>
#include <string>
#include "Models/EGender.h"

std::map<std::string, EGender> ff() {

}

int main(int argc, char **argv) {
	ff();
    CLI::App app{"Lab1"};
	auto addWorkerSubcommand = app.add_subcommand("add-worker");
	auto name = std::string();
	addWorkerSubcommand->add_option("--name,-n", name, "Worker's name")->required(true);
	auto middleName = std::string();
	addWorkerSubcommand->add_option("--middle-name,-m", middleName, "Worker's middle-name")->required(true);
	auto surname = std::string();
	addWorkerSubcommand->add_option("--surname,-s", surname, "Worker's surname")->required(true);
	
	
	auto addUserSubcommand = app.add_subcommand("add-user");
	

    CLI11_PARSE(app);
    return 0;
}