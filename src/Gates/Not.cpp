/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** Not
*/

#include "../../inc/Gates/Not.hpp"

nts::Not::Not(std::string const name) : nts::AComponent(name, 2, nts::Undefined, "Not") {}

void nts::Not::simulate(std::size_t tick)
{
    if (this->_InPins[0].state == nts::Tristate::True)
        this->_OutPins[0].state = nts::Tristate::False;
    else if (this->_InPins[0].state == nts::Tristate::False)
        this->_OutPins[0].state = nts::Tristate::True;
    else
        this->_OutPins[0].state = nts::Tristate::Undefined;
}