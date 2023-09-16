/*
** EPITECH PROJECT, 2023
** nts
** File description:
** 4069
*/

#include "../../inc/Advanced/4069.hpp"

nts::Snot::Snot(std::string const name) : nts::AComponent(name, 12, nts::Undefined, "4069") {}

void nts::Snot::simulate(std::size_t tick)
{
    if (this->_InPins[0].state == nts::Tristate::True)
        this->_OutPins[0].state = nts::Tristate::False;
    else if (this->_InPins[0].state == nts::Tristate::False)
        this->_OutPins[0].state = nts::Tristate::True;
    else
        this->_OutPins[0].state = nts::Tristate::Undefined;

    if (this->_InPins[1].state == nts::Tristate::True)
        this->_OutPins[1].state = nts::Tristate::False;
    else if (this->_InPins[1].state == nts::Tristate::False)
        this->_OutPins[1].state = nts::Tristate::True;
    else
        this->_OutPins[1].state = nts::Tristate::Undefined;

    if (this->_InPins[2].state == nts::Tristate::True)
        this->_OutPins[2].state = nts::Tristate::False;
    else if (this->_InPins[2].state == nts::Tristate::False)
        this->_OutPins[2].state = nts::Tristate::True;
    else
        this->_OutPins[2].state = nts::Tristate::Undefined;

    if (this->_InPins[3].state == nts::Tristate::True)
        this->_OutPins[3].state = nts::Tristate::False;
    else if (this->_InPins[3].state == nts::Tristate::False)
        this->_OutPins[3].state = nts::Tristate::True;
    else
        this->_OutPins[3].state = nts::Tristate::Undefined;

    if (this->_InPins[4].state == nts::Tristate::True)
        this->_OutPins[4].state = nts::Tristate::False;
    else if (this->_InPins[4].state == nts::Tristate::False)
        this->_OutPins[4].state = nts::Tristate::True;
    else
        this->_OutPins[4].state = nts::Tristate::Undefined;

    if (this->_InPins[5].state == nts::Tristate::True)
        this->_OutPins[5].state = nts::Tristate::False;
    else if (this->_InPins[5].state == nts::Tristate::False)
        this->_OutPins[5].state = nts::Tristate::True;
    else
        this->_OutPins[5].state = nts::Tristate::Undefined;
}
