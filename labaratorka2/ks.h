#pragma once
#include <string>
#include <iostream>
#include <fstream>
class ks
{
    int id;
public:
    ks();
    static int MaxID;
    std::string name;
    int ammountceh;
    int ammountcehwork;
    float index;

    friend std::ostream& operator << (std::ostream& out, const ks& t);
    friend std::istream& operator >> (std::istream& in, ks& t);
    friend std::ofstream& operator << (std::ofstream& fout, const ks& t);
    friend std::ifstream& operator >> (std::ifstream& fin, ks& t);
};

