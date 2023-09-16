/*
** EPITECH PROJECT, 2023
** nts
** File description:
** 4081
*/

#pragma once

#include "../AComponent.hpp"

namespace nts {
    class Fand : public nts::AComponent {
        public:
            Fand(std::string const name);
            void simulate (std::size_t tick) override;
    };
}
