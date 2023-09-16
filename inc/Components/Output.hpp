/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** Output
*/

#pragma once

#include "../AComponent.hpp"

namespace nts {
    class Output : public nts::AComponent {
        public:
            Output(std::string const name);
            void simulate (std::size_t tick) override;
    };
}
