#include "truba.h"
#include "utils.h"
using namespace std;

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
    checking(p.id, "������� �������������: ");
    checking(p.dlina, "������� ����� �����: ");
    checking(p.diam, "������� ������� �����: ");
    checking(p.repair, "� �������?: ");
    return in;
}
