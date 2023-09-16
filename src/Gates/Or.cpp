/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** Or
*/

#include "../../inc/Gates/Or.hpp"

nts::Or::Or(std::string const name) : nts::AComponent(name, 3, nts::Undefined, "Or") {}

void nts::Or::simulate(std::size_t tick)
{
    if (this->_InPins[0].state == nts::Tristate::False && this->_InPins[1].state == nts::Tristate::False)
        this->_OutPins[0].state = nts::Tristate::False;
    else if ((this->_InPins[0].state == nts::Tristate::Undefined && this->_InPins[1].state == nts::Tristate::False) || (this->_InPins[0].state == nts::Tristate::False && this->_InPins[1].state == nts::Tristate::Undefined) || (this->_InPins[0].state == nts::Tristate::Undefined && this->_InPins[1].state == nts::Tristate::Undefined))
        this->_OutPins[0].state = nts::Tristate::Undefined;
    else
        this->_OutPins[0].state = nts::Tristate::True;
}
