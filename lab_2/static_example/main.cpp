#include <TCustomCLI.hpp>

int main(int argc, char **argv) {
    auto cli = TCustomCLI("lab_2_static");
    CLI11_PARSE(cli);
    return 0;
}