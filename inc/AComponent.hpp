/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** CompoInfo
*/

#pragma once

#include "IComponent.hpp"

enum InputType {
    Input,
    Output,
    Clock,
    True,
    False
};

enum GateType {
    And,
    Or,
    Xor,
    Not
};

typedef struct pin_info_s {
    std::size_t value;
    nts::IComponent *Fcomponent;
    std::size_t Fpin;
    nts::IComponent *Bcomponent;
    std::size_t Bpin;
    nts::Tristate state;
} pin_info_s;

namespace nts {
    class AComponent : public nts::IComponent {
        public:
            explicit AComponent(std::string const name, std::size_t nbPins, nts::Tristate state, std::string const type);
            nts::Tristate compute(std::size_t pin) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void setLinkBack(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            std::string getName() const override;
            std::string getType() const override;
            std::string getLinkName() override;
            bool isInput(std::string) override;
            std::vector<pin_info_s> &getInPins() override;
            std::vector<pin_info_s> &getOutPins() override;
        protected:
            std::string _name;
            std::size_t _nbPins;
            std::string _type;
            std::vector<pin_info_s> _InPins;
            std::vector<pin_info_s> _OutPins;
    };
}
