/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** Not
*/

#pragma once

#include "../AComponent.hpp"

namespace nts {
    class Not : public nts::AComponent {
        public:
            Not(std::string const name);
            void simulate (std::size_t tick) override;
    };
}
