/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** Xor
*/

#include "../../inc/Gates/Xor.hpp"

nts::Xor::Xor(std::string const name) : nts::AComponent(name, 3, nts::Undefined, "Xor") {}

void nts::Xor::simulate(std::size_t tick)
{
    if ((this->_InPins[0].state == nts::Tristate::False && this->_InPins[1].state == nts::Tristate::False) || (this->_InPins[0].state == nts::Tristate::True && this->_InPins[1].state == nts::Tristate::True))
        this->_OutPins[0].state = nts::Tristate::False;
    else if ((this->_InPins[0].state == nts::Tristate::False && this->_InPins[1].state == nts::Tristate::True) || (this->_InPins[0].state == nts::Tristate::True && this->_InPins[1].state == nts::Tristate::False))
        this->_OutPins[0].state = nts::Tristate::True;
    else
        this->_OutPins[0].state = nts::Tristate::Undefined;
}
