#include "ks.h"
#include "utils.h"
using namespace std;
int ks::MaxID = 0;

ks::ks()
{
    id = ++MaxID;
}

void ks::editing_ks()
{
    ammountcehwork = checking(0, ammountceh, "������� ���������� ������� �����: ");
}

int ks::GetId()
{
    return id;
}

unsigned int ks::GetMaxID()
{
    return MaxID;
}
int ks::Get_ammountceh()
{
    return ammountceh;
}

int ks::Get_ammountcehwork()
{
    return ammountcehwork;
}

std::string ks::Get_Name()
{
    return name;
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
    cin.ignore(1, '\n');
    getline(cin, t.name);
    cout << "������� ���������� �����: ";
    t.ammountceh = checking(0,1000, "������� ���������� �����: ");
    cout << "������� ���������� ���������� �����: ";
    t.ammountcehwork = checking(0,t.ammountceh, "������� ���������� ���������� �����: ");
    cout << "������� ����������:";
    t.index = checking(0, 1, "������� ����������:");
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