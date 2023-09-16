/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** parser
*/

#pragma once

#include "../Nts.hpp"

namespace nts {
    typedef struct chipset_types_s {
        std::string type;
        std::string name;
    } chipset_types_t;

    class Parser {
        public:
            Parser();
            ~Parser();
            void raiseError(int error);
            void parseFile(std::string file, std::vector<std::unique_ptr<nts::IComponent>> &components);
        protected:
            std::string _file;
            int _chipsets = 0;
            int _links = 0;
        private:
    };
}
