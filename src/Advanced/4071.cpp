/*
** EPITECH PROJECT, 2023
** nts
** File description:
** 4071
*/

#include "../../inc/Advanced/4071.hpp"

nts::For::For(std::string const name) : nts::AComponent(name, 12, nts::Undefined, "4071") {}

void nts::For::simulate(std::size_t tick)
{
    if (this->_InPins[0].state == nts::Tristate::False && this->_InPins[1].state == nts::Tristate::False)
        this->_OutPins[0].state = nts::Tristate::False;
    else if ((this->_InPins[0].state == nts::Tristate::Undefined && this->_InPins[1].state == nts::Tristate::False) || (this->_InPins[0].state == nts::Tristate::False && this->_InPins[1].state == nts::Tristate::Undefined) || (this->_InPins[0].state == nts::Tristate::Undefined && this->_InPins[1].state == nts::Tristate::Undefined))
        this->_OutPins[0].state = nts::Tristate::Undefined;
    else
        this->_OutPins[0].state = nts::Tristate::True;

    if (this->_InPins[2].state == nts::Tristate::False && this->_InPins[3].state == nts::Tristate::False)
        this->_OutPins[1].state = nts::Tristate::False;
    else if ((this->_InPins[2].state == nts::Tristate::Undefined && this->_InPins[3].state == nts::Tristate::False) || (this->_InPins[2].state == nts::Tristate::False && this->_InPins[3].state == nts::Tristate::Undefined) || (this->_InPins[2].state == nts::Tristate::Undefined && this->_InPins[3].state == nts::Tristate::Undefined))
        this->_OutPins[1].state = nts::Tristate::Undefined;
    else
        this->_OutPins[1].state = nts::Tristate::True;

    if (this->_InPins[4].state == nts::Tristate::False && this->_InPins[5].state == nts::Tristate::False)
        this->_OutPins[2].state = nts::Tristate::False;
    else if ((this->_InPins[4].state == nts::Tristate::Undefined && this->_InPins[5].state == nts::Tristate::False) || (this->_InPins[4].state == nts::Tristate::False && this->_InPins[5].state == nts::Tristate::Undefined) || (this->_InPins[4].state == nts::Tristate::Undefined && this->_InPins[5].state == nts::Tristate::Undefined))
        this->_OutPins[2].state = nts::Tristate::Undefined;
    else
        this->_OutPins[2].state = nts::Tristate::True;

    if (this->_InPins[6].state == nts::Tristate::False && this->_InPins[7].state == nts::Tristate::False)
        this->_OutPins[3].state = nts::Tristate::False;
    else if ((this->_InPins[6].state == nts::Tristate::Undefined && this->_InPins[7].state == nts::Tristate::False) || (this->_InPins[6].state == nts::Tristate::False && this->_InPins[7].state == nts::Tristate::Undefined) || (this->_InPins[6].state == nts::Tristate::Undefined && this->_InPins[7].state == nts::Tristate::Undefined))
        this->_OutPins[3].state = nts::Tristate::Undefined;
    else
        this->_OutPins[3].state = nts::Tristate::True;
}
