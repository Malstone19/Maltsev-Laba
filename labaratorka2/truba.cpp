#include "truba.h"
#include "utils.h"
using namespace std;

int truba::MaxID = 0;

truba::truba()
{
    id = ++MaxID;
}

unsigned int truba::GetMaxID()
{
    return MaxID;
}

void truba::editing_pipe()
{
    repair = !repair;
    cout << "Успешно изменена на " << repair << endl;
}

int truba::GetId()
{
    return id;
}
bool truba::GetRepair()
{
    return repair;
}

ostream& operator << (ostream& out, const truba& p)
{
    cout << endl;
    cout << "Труба" << endl;
    cout << "Идентификатор трубы: " << p.id << endl;
    cout << "Длина трубы: " << p.dlina << endl;
    cout << "Диаметр трубы: " << p.diam << endl;
    cout << "Ремонт?: " << p.repair << endl;
    return out;
}
istream& operator >> (istream& in, truba& p)
{
    cout << "Введите длину трубы: ";
    p.dlina = checking(0,300, "Введите длину трубы: ");
    cout << "Введите диаметр трубы: ";
    p.diam = checking(0, 300, "Введите диаметр трубы: ");
    cout << "В ремонте?: ";
    p.repair = checking(0, 1, "В ремонте?: ");
    return in;
}

ofstream& operator << (ofstream& fout, const truba& p)
{
    fout << endl << p.id << endl << p.dlina << endl << p.diam << endl << p.repair;
    return fout;
}

ifstream& operator >> (ifstream& fin, truba& p)
{
    fin >> p.id >> p.dlina >> p.diam >> p.repair;
    return fin;
}
