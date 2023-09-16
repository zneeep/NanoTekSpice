/*
** EPITECH PROJECT, 2023
** nts
** File description:
** 4030
*/

#pragma once

#include "../AComponent.hpp"

namespace nts {
    class Fxor : public nts::AComponent {
        public:
            Fxor(std::string const name);
            void simulate (std::size_t tick) override;
    };
}
