#include "truba.h"
#include "utils.h"
using namespace std;

int truba::MaxID = 0;

truba::truba()
{
    id = ++MaxID;
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
    checking(p.dlina, "Введите длину трубы: ");
    checking(p.diam, "Введите диаметр трубы: ");
    checking(p.repair, "В ремонте?: ");
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
