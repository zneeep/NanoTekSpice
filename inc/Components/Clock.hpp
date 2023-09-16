/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** Clock
*/

#pragma once

#include "../AComponent.hpp"

namespace nts {
    class Clock : public nts::AComponent {
        public:
            Clock(std::string const name);
            void simulate (std::size_t tick) override;
    };
}
