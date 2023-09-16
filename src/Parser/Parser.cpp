/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** parser
*/

#include "../inc/Parser/Parser.hpp"

nts::Parser::Parser() {}

nts::Parser::~Parser()
{
}

void nts::Parser::raiseError(int error)
{
    switch (error) {
        case 1:
            throw std::invalid_argument("Error: Invalid file.");
            break;
        case 2:
            throw std::invalid_argument("Error: The circuit file includes one or several lexical or syntactic errors.");
            break;
        case 3:
            throw std::invalid_argument("Error: A component type is unknown.");
            break;
        case 4:
            throw std::invalid_argument("Error: A component name is unknown.");
            break;
        case 5:
            throw std::invalid_argument("Error: Several components share the same name.");
            break;
        case 6:
            throw std::invalid_argument("Error: There is no chipset in the circuit.");
            break;
        case 7:
            throw std::invalid_argument("Error: There is no link in the circuit.");
            break;
        case 8:
            throw std::invalid_argument("Error: The file is empty.");
            break;
        default:
            break;
    }
}

void nts::Parser::parseFile(std::string file, std::vector<std::unique_ptr<nts::IComponent>> &components)
{
    nts::Factory factory;
    // open file
    std::ifstream ifs(file);
    std::string line;

    bool check_chipsets = false;
    bool check_links = false;
    int check_name = 0;

    // check if file is open
    if (!ifs.is_open())
        raiseError(1);

    // check if file is empty
    if (ifs.peek() == std::ifstream::traits_type::eof())
        raiseError(8);

    // read file line by line
    while (std::getline(ifs, line)) {
        // copy line in a buffer without comments
        if (line.find('#') != std::string::npos)
            line = line.substr(0, line.find('#'));
        // check if line is empty
        if (line[0] == '#' || line[0] == '\0')
            continue;
        // check if line is .chipsets: or .links:
        if (line.substr(0, 11) == ".chipsets:") {
            _chipsets++;
            check_chipsets = true, check_links = false;
            continue;
        } else if (line.substr(0, 7) == ".links:") {
            _links++;
            check_links = true, check_chipsets = false;
            continue;
        }
        if (check_chipsets == true) {
            std::string chiptype = line.substr(0, line.find(' '));
            std::string chipname = line.substr(line.find(' ') + 1, line.size());
            if (chiptype != "input" && chiptype != "output" && chiptype != "clock" && chiptype != "true" && chiptype != "false" && chiptype != "and" && chiptype != "not" &&  chiptype != "or" &&  chiptype != "xor" && chiptype != "4001" && chiptype != "4008" && chiptype != "4011" && chiptype != "4013" && chiptype != "4017" && chiptype != "4030" && chiptype != "4040" && chiptype != "4069" && chiptype != "4071" && chiptype != "4081" && chiptype != "4094" && chiptype != "4514" && chiptype != "4801" && chiptype != "2716")
                raiseError(3);
            // check if chipname is already used
            for (unsigned long i = 0; i < components.size(); i++) {
                if (components[i]->getName() == chipname)
                    raiseError(5);
            }
            std::unique_ptr<nts::IComponent> comp = factory.createComponent(chiptype, chipname);
            components.push_back(std::move(comp));
        } else if (check_links == true) {
            std::string link1 = line.substr(0, line.find(' '));
            std::string link2 = line.substr(line.find(' ') + 1, line.size());
            std::string chip1 = link1.substr(0, link1.find(':'));
            std::string pin1 = link1.substr(link1.find(':') + 1, link1.size());
            std::string chip2 = link2.substr(0, link2.find(':'));
            std::string pin2 = link2.substr(link2.find(':') + 1, link2.size());
            for (unsigned long i = 0; i < components.size(); i++) {
                if (components[i]->getName() == chip1) {
                    check_name++;
                    for (unsigned long j = 0; j < components.size(); j++) {
                        if (components[j]->getName() == chip2) {
                            check_name++;
                            if (components[i]->getType() == "Output") {
                                components[j]->setLink(std::stoi(pin2), *components[i], std::stoi(pin1));
                                components[i]->setLinkBack(std::stoi(pin1), *components[j], std::stoi(pin2));
                            } else {
                                components[i]->setLink(std::stoi(pin1), *components[j], std::stoi(pin2));
                                components[j]->setLinkBack(std::stoi(pin2), *components[i], std::stoi(pin1));
                            }
                        }
                    }
                }
            }
            if (check_name != 2) {
                raiseError(4);
            }
            check_name = 0;
        }
    }
    // check if there is no components
    if (_chipsets < 1)
        raiseError(6);
    if (_links < 1)
        raiseError(7);

    // close file
    ifs.close();
}
