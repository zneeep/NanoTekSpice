/*
** EPITECH PROJECT, 2023
** B-OOP-400-LYN-4-1-tekspice-arthur.pahon
** File description:
** Acomponent
*/

#include "../inc/AComponent.hpp"

nts::AComponent::AComponent(std::string const name, std::size_t nbPins, nts::Tristate state, std::string const type) : _name(name), _nbPins(nbPins), _type(type)
{
    pin_info_s pin = { 0, nullptr, 0, nullptr, 0, state};
    if (type == "Input" || type == "True" || type == "False" || type == "Clock")
        _OutPins.push_back(pin);
    if (type == "Output")
        _InPins.push_back(pin);
    if (type == "And" || type == "Or" || type == "Xor") {
        for (std::size_t i = 0; i < 2; ++i) {
            pin_info_s inpin = { i, nullptr, 0, nullptr, 0, state};
            _InPins.push_back(inpin);
        }
        _OutPins.push_back(pin);
    }
    if (type == "Not") {
        _InPins.push_back(pin);
        _OutPins.push_back(pin);
    }
    if (type == "4001" || type == "4011" || type == "4030" || type == "4071" || type == "4081") {
        for (std::size_t i = 0; i < 8; ++i) {
            pin_info_s inpin = { i, nullptr, 0, nullptr, 0, state};
            _InPins.push_back(inpin);
        }
        for (std::size_t i = 0; i < 4; ++i) {
            pin_info_s outpin = { i, nullptr, 0, nullptr, 0, state};
            _OutPins.push_back(outpin);
        }
    }
    if (type == "4069") {
        for (std::size_t i = 0; i < 6; ++i) {
            pin_info_s inpin = { i, nullptr, 0, nullptr, 0, state};
            _InPins.push_back(inpin);
            _OutPins.push_back(inpin);
        }
    }
}

nts::Tristate nts::AComponent::compute(std::size_t pin)
{
    if (pin > _nbPins)
        throw std::invalid_argument("Pin doesn't exist");
    if (_type == "Input" || _type == "True" || _type == "False" || _type == "Output" || _type == "Clock")
        return _OutPins.at(pin - 1).state;
    if (_type == "And" || _type == "Or" || _type == "Xor" || _type == "Not")
        return _OutPins.at(pin - 1).state;
    return nts::Tristate::Undefined;
}

void nts::AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (_type == "4001" || _type == "4011" || _type == "4030" || _type == "4069" || _type == "4071" || _type == "4081") {
        if (pin > 13)
            throw std::invalid_argument("Pin doesn't exist");
    } else {
        if (pin > _nbPins)
            throw std::invalid_argument("Pin doesn't exist");
    }
    if (_type == "Input" || _type == "True" || _type == "False" || _type == "Clock") {
        _OutPins.at(pin - 1).Fcomponent = &other;
        _OutPins.at(pin - 1).Fpin = otherPin;
    }
    if (_type == "Output") {
        _InPins.at(pin - 1).Fcomponent = &other;
        _InPins.at(pin - 1).Fpin = otherPin;
    }
    if (_type == "And" || _type == "Or" || _type == "Xor") {
        if (pin <= 2) {
            _InPins.at(pin - 1).Fcomponent = &other;
            _InPins.at(pin - 1).Fpin = otherPin;
        } else {
            _OutPins.at(0).Fcomponent = &other;
            _OutPins.at(0).Fpin = otherPin;
        }
    }
    if (_type == "Not") {
        if (pin == 1) {
            _InPins.at(0).Fcomponent = &other;
            _InPins.at(0).Fpin = otherPin;
        } else {
            _OutPins.at(0).Fcomponent = &other;
            _OutPins.at(0).Fpin = otherPin;
        }
    }
    if (_type == "4001" || _type == "4011" || _type == "4030" || _type == "4071" || _type == "4081") {
        if (pin <= 2) {
            _InPins.at(pin - 1).Fcomponent = &other;
            _InPins.at(pin - 1).Fpin = otherPin;
        } else if (pin == 3 || pin == 4) {
            _OutPins.at(pin - 3).Fcomponent = &other;
            _OutPins.at(pin - 3).Fpin = otherPin;
        } else if (pin == 5 || pin == 6) {
            _InPins.at(pin - 3).Fcomponent = &other;
            _InPins.at(pin - 3).Fpin = otherPin;
        } else if (pin == 8 || pin == 9) {
            _InPins.at(pin - 4).Fcomponent = &other;
            _InPins.at(pin - 4).Fpin = otherPin;
        } else if (pin == 10 || pin == 11) {
            _OutPins.at(pin - 8).Fcomponent = &other;
            _OutPins.at(pin - 8).Fpin = otherPin;
        } else if (pin == 12 || pin == 13) {
            _InPins.at(pin - 6).Fcomponent = &other;
            _InPins.at(pin - 6).Fpin = otherPin;
        }
    }
    if (_type == "4069") {
        if (pin%2 == 0) {
            _OutPins.at(pin/2 - 1).Fcomponent = &other;
            _OutPins.at(pin/2 - 1).Fpin = otherPin;
        } else if (pin == 1) {
            _InPins.at(0).Fcomponent = &other;
            _InPins.at(0).Fpin = otherPin;
        } else if (pin == 3) {
            _InPins.at(1).Fcomponent = &other;
            _InPins.at(1).Fpin = otherPin;
        } else if (pin == 5) {
            _InPins.at(2).Fcomponent = &other;
            _InPins.at(2).Fpin = otherPin;
        } else if (pin == 9) {
            _InPins.at(3).Fcomponent = &other;
            _InPins.at(3).Fpin = otherPin;
        } else if (pin == 11) {
            _InPins.at(4).Fcomponent = &other;
            _InPins.at(4).Fpin = otherPin;
        } else if (pin == 13) {
            _InPins.at(5).Fcomponent = &other;
            _InPins.at(5).Fpin = otherPin;
        }
    }
}

void nts::AComponent::setLinkBack(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (_type == "4001" || _type == "4011" || _type == "4030" || _type == "4069" || _type == "4071" || _type == "4081") {
        if (pin > 13)
            throw std::invalid_argument("Pin doesn't exist");
    } else {
        if (pin > _nbPins)
            throw std::invalid_argument("Pin doesn't exist");
    }
    if (_type == "Input" || _type == "True" || _type == "False" || _type == "Clock") {
        _OutPins.at(pin - 1).Bcomponent = &other;
        _OutPins.at(pin - 1).Bpin = otherPin;
    }
    if (_type == "Output") {
        _InPins.at(pin - 1).Bcomponent = &other;
        _InPins.at(pin - 1).Bpin = otherPin;
    }
    if (_type == "And" || _type == "Or" || _type == "Xor") {
        if (pin <= 2) {
            _InPins.at(pin - 1).Bcomponent = &other;
            _InPins.at(pin - 1).Bpin = otherPin;
        } else {
            _OutPins.at(0).Bcomponent = &other;
            _OutPins.at(0).Bpin = otherPin;
        }
    }
    if (_type == "Not") {
        if (pin == 1) {
            _InPins.at(0).Bcomponent = &other;
            _InPins.at(0).Bpin = otherPin;
        } else {
            _OutPins.at(0).Bcomponent = &other;
            _OutPins.at(0).Bpin = otherPin;
        }
    }
    if (_type == "4001" || _type == "4011" || _type == "4030" || _type == "4071" || _type == "4081") {
        if (pin <= 2) {
            _InPins.at(pin - 1).Bcomponent = &other;
            _InPins.at(pin - 1).Bpin = otherPin;
        } else if (pin == 3 || pin == 4) {
            _OutPins.at(pin - 3).Bcomponent = &other;
            _OutPins.at(pin - 3).Bpin = otherPin;
        } else if (pin == 5 || pin == 6) {
            _InPins.at(pin - 3).Bcomponent = &other;
            _InPins.at(pin - 3).Bpin = otherPin;
        } else if (pin == 8 || pin == 9) {
            _InPins.at(pin - 4).Bcomponent = &other;
            _InPins.at(pin - 4).Bpin = otherPin;
        } else if (pin == 10 || pin == 11) {
            _OutPins.at(pin - 8).Bcomponent = &other;
            _OutPins.at(pin - 8).Bpin = otherPin;
        } else if (pin == 12 || pin == 13) {
            _InPins.at(pin - 6).Bcomponent = &other;
            _InPins.at(pin - 6).Bpin = otherPin;
        }
    }
    if (_type == "4069") {
        if (pin%2 == 0) {
            _OutPins.at(pin/2 - 1).Bcomponent = &other;
            _OutPins.at(pin/2 - 1).Bpin = otherPin;
        } else if (pin == 1) {
            _InPins.at(0).Bcomponent = &other;
            _InPins.at(0).Bpin = otherPin;
        } else if (pin == 3) {
            _InPins.at(1).Bcomponent = &other;
            _InPins.at(1).Bpin = otherPin;
        } else if (pin == 5) {
            _InPins.at(2).Bcomponent = &other;
            _InPins.at(2).Bpin = otherPin;
        } else if (pin == 9) {
            _InPins.at(3).Bcomponent = &other;
            _InPins.at(3).Bpin = otherPin;
        } else if (pin == 11) {
            _InPins.at(4).Bcomponent = &other;
            _InPins.at(4).Bpin = otherPin;
        } else if (pin == 13) {
            _InPins.at(5).Bcomponent = &other;
            _InPins.at(5).Bpin = otherPin;
        }
    }
}

std::string nts::AComponent::getName() const
{
    return this->_name;
}

std::string nts::AComponent::getType() const
{
    return this->_type;
}

std::string nts::AComponent::getLinkName()
{
    return this->_InPins[0].Fcomponent->getName();

}

bool nts::AComponent::isInput(std::string type)
{
    if (type == "Input" || type == "True" || type == "False" || type == "Clock")
        return true;
    return false;
}

std::vector<pin_info_s> &nts::AComponent::getInPins()
{
    return this->_InPins;
}

std::vector<pin_info_s> &nts::AComponent::getOutPins()
{
    return this->_OutPins;
}
