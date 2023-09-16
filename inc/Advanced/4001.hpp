/*
** EPITECH PROJECT, 2023
** nts
** File description:
** 4001
*/

#pragma once

#include "../AComponent.hpp"

namespace nts {
    class Fnor : public nts::AComponent {
        public:
            Fnor(std::string const name);
            void simulate (std::size_t tick) override;
    };
}
