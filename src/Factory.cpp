/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** Factory
*/

#include "../inc/Factory.hpp"

nts::Factory::Factory() {}

nts::Factory::~Factory() {}

std::unique_ptr<nts::IComponent> nts::Factory::createComponent(const std::string &type, const std::string &name)
{
    if (type == "input")
        return std::make_unique<nts::Input>(nts::Input(name));
    if (type == "output")
        return std::make_unique<nts::Output>(nts::Output(name));
    if (type == "clock")
        return std::make_unique<nts::Clock>(nts::Clock(name));
    if (type == "true")
        return std::make_unique<nts::TrueComponent>(nts::TrueComponent(name));
    if (type == "false")
        return std::make_unique<nts::FalseComponent>(nts::FalseComponent(name));
    if (type == "and")
        return std::make_unique<nts::And>(nts::And(name));
    if (type == "not")
        return std::make_unique<nts::Not>(nts::Not(name));
    if (type == "or")
        return std::make_unique<nts::Or>(nts::Or(name));
    if (type == "xor")
        return std::make_unique<nts::Xor>(nts::Xor(name));
    if (type == "4001")
        return std::make_unique<nts::Fnor>(nts::Fnor(name));
    if (type == "4011")
        return std::make_unique<nts::Fnand>(nts::Fnand(name));
    if (type == "4030")
        return std::make_unique<nts::Fxor>(nts::Fxor(name));
    if (type == "4069")
        return std::make_unique<nts::Snot>(nts::Snot(name));
    if (type == "4071")
        return std::make_unique<nts::For>(nts::For(name));
    if (type == "4081")
        return std::make_unique<nts::Fand>(nts::Fand(name));
    return nullptr;
}
