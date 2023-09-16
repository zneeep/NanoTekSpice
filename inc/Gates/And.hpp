/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** And
*/

#pragma once

#include "../AComponent.hpp"

namespace nts {
    class And : public nts::AComponent {
        public:
            And(std::string const name);
            void simulate (std::size_t tick) override;
    };
}
