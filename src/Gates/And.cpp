/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** And
*/

#include "../../inc/Gates/And.hpp"

nts::And::And(std::string const name) : nts::AComponent(name, 3, nts::Undefined, "And") {}

void nts::And::simulate(std::size_t tick)
{
    if (this->_InPins[0].state == nts::Tristate::True && this->_InPins[1].state == nts::Tristate::True)
        this->_OutPins[0].state = nts::Tristate::True;
    else if ((this->_InPins[0].state == nts::Tristate::Undefined && this->_InPins[1].state == nts::Tristate::True) || (this->_InPins[0].state == nts::Tristate::True && this->_InPins[1].state == nts::Tristate::Undefined) || (this->_InPins[0].state == nts::Tristate::Undefined && this->_InPins[1].state == nts::Tristate::Undefined))
        this->_OutPins[0].state = nts::Tristate::Undefined;
    else
        this->_OutPins[0].state = nts::Tristate::False;
}
