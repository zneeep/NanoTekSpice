/*
** EPITECH PROJECT, 2023
** nts
** File description:
** Circuit
*/

#pragma once

#include "Nts.hpp"

namespace nts {
    class Circuit {
        public:
            Circuit();
            void execute(std::vector<std::unique_ptr<nts::IComponent>> &components);
            void command(std::vector<std::unique_ptr<nts::IComponent>> &components);
            void display(std::vector<std::unique_ptr<nts::IComponent>> &components);
            void simulate(std::vector<std::unique_ptr<nts::IComponent>> &components, std::vector<std::string> &todo);
            void algofront(std::string component, std::string nextcomponent, std::vector<std::unique_ptr<nts::IComponent>> &components);
            void loop(std::vector<std::unique_ptr<nts::IComponent>> &components, std::vector<std::string> &todo);
            void execAssign(std::vector<std::unique_ptr<nts::IComponent>> &components, std::vector<std::string> &todo);
            int getTick() const;
            std::size_t getGoodOutput(std::size_t value);
        protected:
            int tick = 0;
            bool isClock = false;
    };
}
