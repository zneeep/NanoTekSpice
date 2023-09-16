/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** True
*/

#include "../../inc/Components/True.hpp"

nts::TrueComponent::TrueComponent(std::string const name) : nts::AComponent(name, 1, nts::True, "True") {}

void nts::TrueComponent::simulate(std::size_t tick) {
    (void)tick;
}
