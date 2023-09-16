/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** Input
*/

#pragma once

#include "../AComponent.hpp"

namespace nts {
    class Input : public nts::AComponent
    {
        public:
            Input(std::string const name);
            void simulate(std::size_t tick) override;
    };
}
