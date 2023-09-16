/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** IComponent
*/

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct pin_info_s;

namespace nts
{
    enum Tristate
    {
        Undefined = (- true),
        True = true,
        False = false
    };

    class IComponent
    {
        public :
            virtual ~IComponent () = default;
            virtual void simulate (std::size_t tick) = 0;
            virtual nts :: Tristate compute (std::size_t pin) = 0;
            virtual void setLink (std::size_t pin, nts::IComponent & other, std::size_t otherPin) = 0;
            virtual void setLinkBack (std::size_t pin, nts::IComponent & other, std::size_t otherPin) = 0;
            virtual std::string getName() const = 0;
            virtual std::string getType() const = 0;
            virtual std::string getLinkName() = 0;
            virtual bool isInput(std::string) = 0;
            virtual std::vector<pin_info_s> &getInPins() = 0;
            virtual std::vector<pin_info_s> &getOutPins() = 0;
    };
}
