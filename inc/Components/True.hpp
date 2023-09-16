/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** True
*/

#pragma once

#include "../AComponent.hpp"

namespace nts {
    class TrueComponent : public nts::AComponent {
        public:
            TrueComponent(std::string const name);
            void simulate (std::size_t tick) override;
    };
}
