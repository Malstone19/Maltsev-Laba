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
    cout << "������� �������� �� " << repair << endl;
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
    cout << "�����" << endl;
    cout << "������������� �����: " << p.id << endl;
    cout << "����� �����: " << p.dlina << endl;
    cout << "������� �����: " << p.diam << endl;
    cout << "������?: " << p.repair << endl;
    return out;
}
istream& operator >> (istream& in, truba& p)
{
    cout << "������� ����� �����: ";
    p.dlina = checking(0,300, "������� ����� �����: ");
    cout << "������� ������� �����: ";
    p.diam = checking(0, 300, "������� ������� �����: ");
    cout << "� �������?: ";
    p.repair = checking(0, 1, "� �������?: ");
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
