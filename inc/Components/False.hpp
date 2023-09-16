/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** False
*/

#pragma once

#include "../AComponent.hpp"

namespace nts {
    class FalseComponent : public nts::AComponent {
        public:
            FalseComponent(std::string const name);
            void simulate (std::size_t tick) override;
    };
}
