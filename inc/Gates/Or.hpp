/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** Or
*/

#pragma once

#include "../AComponent.hpp"

namespace nts {
    class Or : public nts::AComponent {
        public:
            Or(std::string const name);
            void simulate (std::size_t tick) override;
    };
}
