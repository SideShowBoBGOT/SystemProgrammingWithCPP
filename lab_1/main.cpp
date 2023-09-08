#include <iostream>
#include <string>

#include <CLI/CLI.hpp>

#include "Views/TCustomCLI.h"

int main(int argc, char **argv) {
    auto cli = TCustomCLI("lab_1");
    CLI11_PARSE(cli);
    return 0;
}