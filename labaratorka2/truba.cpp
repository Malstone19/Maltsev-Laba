#include "truba.h"
#include "utils.h"
using namespace std;

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
    checking(p.id, "Введите идентификатор: ");
    checking(p.dlina, "Введите длину трубы: ");
    checking(p.diam, "Введите диаметр трубы: ");
    checking(p.repair, "В ремонте?: ");
    return in;
}
