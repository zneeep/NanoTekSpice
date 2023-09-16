/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** Factory
*/

#pragma once

#include "Nts.hpp"

namespace nts {
    class Factory {
        public:
            Factory();
            ~Factory();
            std::unique_ptr<nts::IComponent> createComponent(const std::string &type, const std::string &name);
        protected:
        private:
    };
}