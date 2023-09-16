/*
** EPITECH PROJECT, 2023
** nts
** File description:
** 4069
*/

#pragma once

#include "../AComponent.hpp"

namespace nts {
    class Snot : public nts::AComponent {
        public:
            Snot(std::string const name);
            void simulate (std::size_t tick) override;
    };
}
