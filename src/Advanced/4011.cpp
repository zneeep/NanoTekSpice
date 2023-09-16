/*
** EPITECH PROJECT, 2023
** nts
** File description:
** 4011
*/

#include "../../inc/Advanced/4011.hpp"

nts::Fnand::Fnand(std::string const name) : nts::AComponent(name, 12, nts::Undefined, "4011") {}

void nts::Fnand::simulate(std::size_t tick)
{
    if (this->_InPins[0].state == nts::Tristate::True && this->_InPins[1].state == nts::Tristate::True)
        this->_OutPins[0].state = nts::Tristate::False;
    else if ((this->_InPins[0].state == nts::Tristate::Undefined && this->_InPins[1].state == nts::Tristate::True) || (this->_InPins[0].state == nts::Tristate::True && this->_InPins[1].state == nts::Tristate::Undefined) || (this->_InPins[0].state == nts::Tristate::Undefined && this->_InPins[1].state == nts::Tristate::Undefined))
        this->_OutPins[0].state = nts::Tristate::Undefined;
    else
        this->_OutPins[0].state = nts::Tristate::True;

    if (this->_InPins[2].state == nts::Tristate::True && this->_InPins[3].state == nts::Tristate::True)
        this->_OutPins[1].state = nts::Tristate::False;
    else if ((this->_InPins[2].state == nts::Tristate::Undefined && this->_InPins[3].state == nts::Tristate::True) || (this->_InPins[2].state == nts::Tristate::True && this->_InPins[3].state == nts::Tristate::Undefined) || (this->_InPins[2].state == nts::Tristate::Undefined && this->_InPins[3].state == nts::Tristate::Undefined))
        this->_OutPins[1].state = nts::Tristate::Undefined;
    else
        this->_OutPins[1].state = nts::Tristate::True;

    if (this->_InPins[4].state == nts::Tristate::True && this->_InPins[5].state == nts::Tristate::True)
        this->_OutPins[2].state = nts::Tristate::False;
    else if ((this->_InPins[4].state == nts::Tristate::Undefined && this->_InPins[5].state == nts::Tristate::True) || (this->_InPins[4].state == nts::Tristate::True && this->_InPins[5].state == nts::Tristate::Undefined) || (this->_InPins[4].state == nts::Tristate::Undefined && this->_InPins[5].state == nts::Tristate::Undefined))
        this->_OutPins[2].state = nts::Tristate::Undefined;
    else
        this->_OutPins[2].state = nts::Tristate::True;

    if (this->_InPins[6].state == nts::Tristate::True && this->_InPins[7].state == nts::Tristate::True)
        this->_OutPins[3].state = nts::Tristate::False;
    else if ((this->_InPins[6].state == nts::Tristate::Undefined && this->_InPins[7].state == nts::Tristate::True) || (this->_InPins[6].state == nts::Tristate::True && this->_InPins[7].state == nts::Tristate::Undefined) || (this->_InPins[6].state == nts::Tristate::Undefined && this->_InPins[7].state == nts::Tristate::Undefined))
        this->_OutPins[3].state = nts::Tristate::Undefined;
    else
        this->_OutPins[3].state = nts::Tristate::True;
}