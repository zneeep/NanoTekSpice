/*
** EPITECH PROJECT, 2023
** nts
** File description:
** 4011
*/

#pragma once

#include "../AComponent.hpp"

namespace nts {
    class Fnand : public nts::AComponent {
        public:
            Fnand(std::string const name);
            void simulate (std::size_t tick) override;
    };
}
