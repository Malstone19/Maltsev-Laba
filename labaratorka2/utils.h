#pragma once
#include <iostream>
#include <string>



template <typename T>

void checking(T& var, std::string com)
{
    do {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << com;
        std::cin >> var;
    } while (var < 0 || std::cin.fail());
}
