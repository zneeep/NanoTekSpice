/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** main
*/

#include "../inc/Nts.hpp"

void description()
{
    std::cout << "USAGE" << std::endl;
    std::cout << "\t./nanotekspice file.nts [input_name=input_value]" << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\tfile.nts\t\tthe circuit file describing the components and their links" << std::endl;
    std::cout << "\tinput_name=input_value\tthe name of an input to set its value (all inputs must be set before the simulation starts)" << std::endl;
}

int firstChecks(int ac, char **av)
{
    if (ac < 2) {
        std::cerr << "Error: not enough arguments" << std::endl;
        return 84;
    }
    if (ac == 2 && std::string(av[1]) == "-h") {
        description();
        exit(0);
    }

    return 0;
}

int main(int ac, char **av)
{
    nts::Parser parser;
    nts::Factory factory;
    nts::Circuit circuit;
    std::vector<std::unique_ptr<nts::IComponent>> components;

    if (firstChecks(ac, av) == 84)
        return 84;
    try {
        parser.parseFile(av[1], components);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    circuit.execute(components);
    return 0;
}
