#pragma once
#include <string>
#include <iostream>
class ks
{
public:
    int id;
    std::string name;
    int ammountceh;
    int ammountcehwork;
    float index;

    friend std::ostream& operator << (std::ostream& out, const ks& t);
    friend std::istream& operator >> (std::istream& in, ks& t);
};

