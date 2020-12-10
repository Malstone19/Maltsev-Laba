#pragma once
#include <iostream>
#include <fstream>
class truba
{
    int id;
    static int MaxID;
public:
    truba();
    float dlina;
    int diam;
    bool repair = false;
    void editing_pipe();
    int GetId();
    bool GetRepair();
    static unsigned int GetMaxID();

    friend std::ostream& operator << (std::ostream& out, const truba& p);
    friend std::istream& operator >> (std::istream& in, truba& p);
    friend std::ofstream& operator << (std::ofstream& fout, const truba& p);
    friend std::ifstream& operator >> (std::ifstream& fin, truba& p);
};

