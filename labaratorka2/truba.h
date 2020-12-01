#pragma once
#include <iostream>
#include <fstream>
class truba
{
    int id;
public:
    truba();
    static int MaxID;
    float dlina;
    float diam;
    bool repair = false;
   

    friend std::ostream& operator << (std::ostream& out, const truba& p);
    friend std::istream& operator >> (std::istream& in, truba& p);
    friend std::ofstream& operator << (std::ofstream& fout, const truba& p);
    friend std::ifstream& operator >> (std::ifstream& fin, truba& p);
};

