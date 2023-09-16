/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** False
*/

#include "../../inc/Components/False.hpp"

nts::FalseComponent::FalseComponent(std::string const name) : nts::AComponent(name, 1, nts::False, "False") {}

void nts::FalseComponent::simulate(std::size_t tick) {
    (void)tick;
}