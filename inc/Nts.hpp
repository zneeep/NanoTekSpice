/*
** EPITECH PROJECT, 2023
** nanotekspice
** File description:
** nano
*/

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <csignal>

#include "IComponent.hpp"
#include "AComponent.hpp"
#include "Factory.hpp"
#include "Circuit.hpp"
#include "Parser/Parser.hpp"
#include "Components/Clock.hpp"
#include "Components/False.hpp"
#include "Components/Input.hpp"
#include "Components/Output.hpp"
#include "Components/True.hpp"
#include "Gates/And.hpp"
#include "Gates/Not.hpp"
#include "Gates/Or.hpp"
#include "Gates/Xor.hpp"
#include "Advanced/4001.hpp"
#include "Advanced/4011.hpp"
#include "Advanced/4030.hpp"
#include "Advanced/4069.hpp"
#include "Advanced/4071.hpp"
#include "Advanced/4081.hpp"
