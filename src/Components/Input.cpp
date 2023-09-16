/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** Input
*/

#include "../../inc/Components/Input.hpp"

nts::Input::Input(std::string const name) : nts::AComponent(name, 1, nts::Undefined, "Input") {}

void nts::Input::simulate(std::size_t tick) {
    (void)tick;
}
