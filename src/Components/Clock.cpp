/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** Clock
*/

#include "../../inc/Components/Clock.hpp"

nts::Clock::Clock(std::string const name) : nts::AComponent(name, 1, nts::Undefined, "Clock") {}

void nts::Clock::simulate(std::size_t tick)
{
    if (this->_OutPins[0].state == nts::Tristate::True)
        this->_OutPins[0].state = nts::Tristate::False;
    else if (this->_OutPins[0].state == nts::Tristate::False)
        this->_OutPins[0].state = nts::Tristate::True;
}
