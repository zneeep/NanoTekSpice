/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** Xor
*/

#pragma once

#include "../AComponent.hpp"

namespace nts {
    class Xor : public AComponent {
        public:
            Xor(std::string const name);
            void simulate (std::size_t tick) override;
    };
}
