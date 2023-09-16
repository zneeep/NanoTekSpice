/*
** EPITECH PROJECT, 2023
** nts
** File description:
** 4071
*/

#pragma once

#include "../AComponent.hpp"

namespace nts {
    class For : public nts::AComponent {
        public:
            For(std::string const name);
            void simulate (std::size_t tick) override;
    };
}
