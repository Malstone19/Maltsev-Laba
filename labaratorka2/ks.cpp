#include "ks.h"
#include "utils.h"
using namespace std;
int ks::MaxID = 0;

ks::ks()
{
    id = ++MaxID;
}

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

ofstream& operator << (ofstream& fout, const ks& t)
{
    fout << endl << t.id << endl << t.name << endl << t.ammountceh << endl << t.ammountcehwork << endl << t.index;
    return fout;
}

ifstream& operator >> (ifstream& fin, ks& t)
{
    fin >> t.id >> t.name >> t.ammountceh >> t.ammountcehwork >> t.index;
    return fin;
}