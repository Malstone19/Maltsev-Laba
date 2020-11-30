#include "ks.h"
#include "utils.h"
using namespace std;

ostream& operator << (ostream& out, const ks& t)
{
    cout << endl;
    cout << "������������� �������" << endl;
    cout << "������������� ��: " << t.id << endl;
    cout << "�������� ��: " << t.name << endl;
    cout << "���������� �����: " << t.ammountceh << endl;
    cout << "���������� ������� �����: " << t.ammountcehwork << endl;
    cout << "����������: " << t.index << endl;
    return out;
}
istream& operator >> (istream& in, ks& t)
{
    checking(t.id, "������� �������������:");
    cout << "������� ��������:";
    cin >> t.name;
    checking(t.ammountceh, "������� ���������� �����:");
    do
    {
        checking(t.ammountcehwork, "������� ���������� ���������� �����:");
    } while (t.ammountcehwork > t.ammountceh);
    checking(t.index, "������� ����������:");
    return in;
}