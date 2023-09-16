/*
** EPITECH PROJECT, 2023
** nts
** File description:
** Circuit
*/

#include "Circuit.hpp"

volatile bool exitLoop = false;

nts::Circuit::Circuit() {}

void nts::Circuit::display(std::vector<std::unique_ptr<nts::IComponent>> &components)
{
    std::vector<std::string> inputs;
    std::vector<std::string> outputs;

    for (auto &component : components)
    {
        if (component->getType() == "Input" || component->getType() == "Clock")
            inputs.push_back(component->getName());
        if (component->getType() == "Output")
            outputs.push_back(component->getName());
    }
    std::cout << "tick: " << tick << std::endl;
    std::cout << "input(s):" << std::endl;
    // class inputs by ascii order
    std::sort(inputs.begin(), inputs.end());
    for (auto &input : inputs)
    {
        for (auto &component : components)
        {
            if (component->getName().compare(input) == 0)
            {
                std::cout << "  " << component->getName() << ": ";
                if (component->getOutPins()[0].state == Tristate::Undefined)
                    std::cout << "U" << std::endl;
                else if (component->getOutPins()[0].state == Tristate::True)
                    std::cout << "1" << std::endl;
                else if (component->getOutPins()[0].state == Tristate::False)
                    std::cout << "0" << std::endl;
            }
        }
    }
    std::cout << "output(s):" << std::endl;
    // class outputs by ascii order
    std::sort(outputs.begin(), outputs.end());
    for (const auto &output : outputs)
    {
        for (const auto &component : components)
        {
            if (component->getName().compare(output) == 0)
            {
                std::cout << "  " << component->getName() << ": ";
                if (component->getInPins()[0].state == Tristate::Undefined)
                    std::cout << "U" << std::endl;
                else if (component->getInPins()[0].state == Tristate::True)
                    std::cout << "1" << std::endl;
                else if (component->getInPins()[0].state == Tristate::False)
                    std::cout << "0" << std::endl;
            }
        }
    }
}

void nts::Circuit::execAssign(std::vector<std::unique_ptr<nts::IComponent>> &components, std::vector<std::string> &todo)
{
    std::string compName;
    std::string value;

    // for (auto &it : todo)
    //     std::cout << it << std::endl;

    for (const auto &str : todo)
    {
        compName = str.substr(0, str.find('='));
        value = str.substr(str.find('=') + 1, '\n');
        for (auto &component : components)
        {
            if (component->getName().compare(compName) == 0)
            {
                if (component->getType() == "Clock")
                    isClock = true;
                if (value.compare("0") == 0)
                    component->getOutPins()[0].state = Tristate::False;
                else if (value.compare("1") == 0)
                    component->getOutPins()[0].state = Tristate::True;
                else if (value.compare("U") == 0)
                    component->getOutPins()[0].state = Tristate::Undefined;
            }
        }
    }
}

// void nts::Circuit::algoback(std::vector<std::unique_ptr<nts::IComponent>> &components)
// {

// }

std::size_t nts::Circuit::getGoodOutput(std::size_t value)
{
    if (value == 0 || value == 1)
        return 0;
    else if (value == 2 || value == 3)
        return 1;
    else if (value == 4 || value == 5)
        return 2;
    else if (value == 6 || value == 7)
        return 3;
}

void nts::Circuit::algofront(std::string prev, std::string next, std::vector<std::unique_ptr<nts::IComponent>> &components)
{
    nts::Tristate state;
    std::size_t pin_value = 0;
    // std::cout << "compos : " << prev << " " << next << std::endl;
    // std::cout << std::endl;
    // for (const auto &comp : components) {
    //     if (comp->getName().compare(prev) == 0) {
    //         std::cout << prev << std::endl;
    //         std::cout << std::endl;
    //         std::cout << "outpins : " << std::endl;
    //         for (const auto &pin : comp->getOutPins()) {
    //             std::cout << "pin " << pin.value << " state : " << pin.state << std::endl;
    //             std::cout << "Fcomp " << pin.Fcomponent->getName() << std::endl;
    //             std::cout << "Fpin " << pin.Fpin << std::endl;
    //         }
    //     std::cout << std::endl;
    //     std::cout << std::endl;
    //     }
    // }
    // for (const auto &comp : components) {
    //     if (comp->getName().compare(next) == 0) {
    //         std::cout << next << std::endl;
    //         std::cout << std::endl;
    //         std::cout << "inpins : " << std::endl;
    //         for (const auto &pin : comp->getInPins()) {
    //             std::cout << "pin " << pin.value << " state : " << pin.state << std::endl;
    //             std::cout << "Bcomp " << pin.Bcomponent->getName() << std::endl;
    //             std::cout << "Bpin " << pin.Bpin << std::endl;
    //         }
    //         std::cout << std::endl;
    //         std::cout << "outpins : " << std::endl;
    //         for (const auto &pin : comp->getOutPins()) {
    //             std::cout << "pin " << pin.value << "state " << pin.state << std::endl;
    //             if (pin.Fcomponent != nullptr)
    //                 std::cout << "Fcomp " << pin.Fcomponent->getName() << std::endl;
    //             std::cout << "Fpin " << pin.Fpin << std::endl;
    //         }
    //     std::cout << std::endl;
    //     std::cout << std::endl;
    //     std::cout << std::endl;
    //     }
    // }
    for (const auto &comp : components)
    {
        if (comp->getName().compare(prev) == 0)
            for (const auto &pin : comp->getOutPins())
            {
                if (pin.Fcomponent->getName().compare(next) == 0)
                    state = comp->getOutPins()[pin.value].state;
            }
    }
    // aller chercher le component nextcomponent dans le vector components
    for (auto &comp : components)
    {
        if (comp->getName().compare(next) == 0)
        {
            // aller chercher le pin du component comp qui a pour nom component
            for (auto &pin : comp->getInPins())
            {
                if (pin.Bcomponent->getName().compare(prev) == 0)
                {
                    comp->getInPins()[pin.value].state = state;
                    pin_value = pin.value;
                }
            }
            comp->simulate(tick);
            if (comp->getType() == "Output")
                return;
            if (comp->getType() == "And" || comp->getType() == "Or" || comp->getType() == "Xor" || comp->getType() == "Not" || comp->getType() == "Nand" || comp->getType() == "Nor" || comp->getType() == "Xnor")
            {
                if (comp->getOutPins()[0].Fcomponent != nullptr)
                {
                    std::string prev = comp->getName();
                    std::string next = comp->getOutPins()[0].Fcomponent->getName();
                    Circuit::algofront(prev, next, components);
                }
            }
            if (comp->getType() == "4001" || comp->getType() == "4011" || comp->getType() == "4030" || comp->getType() == "4071" || comp->getType() == "4081")
            {
                if (comp->getOutPins()[getGoodOutput(pin_value)].Fcomponent != nullptr)
                {
                    std::string prev = comp->getName();
                    std::string next = comp->getOutPins()[getGoodOutput(pin_value)].Fcomponent->getName();
                    Circuit::algofront(prev, next, components);
                }
            }
            if (comp->getType() == "4069")
            {
                if (comp->getOutPins()[pin_value].Fcomponent != nullptr)
                {
                    std::string prev = comp->getName();
                    std::string next = comp->getOutPins()[pin_value].Fcomponent->getName();
                    Circuit::algofront(prev, next, components);
                }
            }
        }
    }
}

void nts::Circuit::simulate(std::vector<std::unique_ptr<nts::IComponent>> &components, std::vector<std::string> &todo)
{
    tick++;
    isClock = false;
    execAssign(components, todo);
    for (const auto &component : components)
    {
        if (component->isInput(component->getType()))
        {
            if (component->getType() == "Clock" && todo.size() == 0)
                component->simulate(tick);
            std::string prev = component->getName();
            std::string next = component->getOutPins()[0].Fcomponent->getName();
            Circuit::algofront(prev, next, components);
        }
    }
}

void sigint_handler(int signal)
{
    // std::cout << "Caught signal " << signal << std::endl;
    exitLoop = true;
}

void nts::Circuit::loop(std::vector<std::unique_ptr<nts::IComponent>> &components, std::vector<std::string> &todo)
{
    signal(SIGINT, sigint_handler);

    while (!exitLoop)
    {
        simulate(components, todo);
        display(components);
    }
}

int nts::Circuit::getTick() const
{
    return tick;
}

void nts::Circuit::execute(std::vector<std::unique_ptr<nts::IComponent>> &components)
{
    std::string command;
    std::vector<std::string> todo;
    simulate(components, todo);
    tick = 0;
    std::cout << "> ";

    while (std::getline(std::cin, command))
    {
        if (command == "exit")
            return;
        else if (command == "display")
            display(components);
        else if (command == "simulate")
        {
            simulate(components, todo);
            todo.clear();
        }
        else if (command == "loop") {
            exitLoop = false;
            loop(components, todo);
            exitLoop = false;
        }
        else if (command.find('=') != std::string::npos)
            todo.push_back(command);
        else
            return;
        std::cout << "> ";
    }
}

// !debug
// std::cout << "compos : " << prev << " " << next << std::endl;
// std::cout << std::endl;
// for (const auto &comp : components) {
//     if (comp->getName().compare(prev) == 0) {
//         std::cout << prev << std::endl;
//         std::cout << std::endl;
//         std::cout << "outpins : " << std::endl;
//         for (const auto &pin : comp->getOutPins()) {
//             std::cout << "pin " << pin.value << " state : " << pin.state << std::endl;
//             std::cout << "Fcomp " << pin.Fcomponent->getName() << std::endl;
//             std::cout << "Fpin " << pin.Fpin << std::endl;
//         }
//     std::cout << std::endl;
//     std::cout << std::endl;
//     }
// }
// for (const auto &comp : components) {
//     if (comp->getName().compare(next) == 0) {
//         std::cout << next << std::endl;
//         std::cout << std::endl;
//         std::cout << "inpins : " << std::endl;
//         for (const auto &pin : comp->getInPins()) {
//             std::cout << "pin " << pin.value << " state : " << pin.state << std::endl;
//             std::cout << "Bcomp " << pin.Bcomponent->getName() << std::endl;
//             std::cout << "Bpin " << pin.Bpin << std::endl;
//         }
//         std::cout << std::endl;
//         std::cout << "outpins : " << std::endl;
//         for (const auto &pin : comp->getOutPins()) {
//             std::cout << "pin " << pin.value << "state " << pin.state << std::endl;
//             if (pin.Fcomponent != nullptr)
//                 std::cout << "Fcomp " << pin.Fcomponent->getName() << std::endl;
//             std::cout << "Fpin " << pin.Fpin << std::endl;
//         }
//     std::cout << std::endl;
//     std::cout << std::endl;
//     std::cout << std::endl;
//     }
// }