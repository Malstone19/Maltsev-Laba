#pragma once
#include <iostream>
class truba
{

public:
    int id;
    float dlina;
    float diam;
    bool repair = false;
   

    friend std::ostream& operator << (std::ostream& out, const truba& p);
    friend std::istream& operator >> (std::istream& in, truba& p);
};

