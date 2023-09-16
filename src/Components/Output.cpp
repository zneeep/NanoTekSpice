/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** Output
*/

#include "../../inc/Components/Output.hpp"

nts::Output::Output(std::string const name) : nts::AComponent(name, 1, nts::Undefined, "Output") {}

void nts::Output::simulate(std::size_t tick) {
    (void)tick;
}
