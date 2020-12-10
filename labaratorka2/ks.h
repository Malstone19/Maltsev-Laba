#pragma once
#include <string>
#include <iostream>
#include <fstream>
class ks
{
    int id;
    static int MaxID;
public:
    ks();
    std::string name;
    int ammountceh;
    int ammountcehwork;
    float index;
    void editing_ks();
    int GetId();
    static unsigned int GetMaxID();

    int Get_ammountceh();

    int Get_ammountcehwork();

    std::string Get_Name();


    friend std::ostream& operator << (std::ostream& out, const ks& t);
    friend std::istream& operator >> (std::istream& in, ks& t);
    friend std::ofstream& operator << (std::ofstream& fout, const ks& t);
    friend std::ifstream& operator >> (std::ifstream& fin, ks& t);
};

