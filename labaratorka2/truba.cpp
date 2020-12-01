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
    cout << "�����" << endl;
    cout << "������������� �����: " << p.id << endl;
    cout << "����� �����: " << p.dlina << endl;
    cout << "������� �����: " << p.diam << endl;
    cout << "������?: " << p.repair << endl;
    return out;
}
istream& operator >> (istream& in, truba& p)
{
    checking(p.dlina, "������� ����� �����: ");
    checking(p.diam, "������� ������� �����: ");
    checking(p.repair, "� �������?: ");
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
