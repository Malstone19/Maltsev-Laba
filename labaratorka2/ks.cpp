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
    ammountcehwork = checking(0, ammountceh, "Введите количество рабочих цехов: ");
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
    cout << "Компрессорная станция" << endl;
    cout << "Идентификатор КС: " << t.id << endl;
    cout << "Название КС: " << t.name << endl;
    cout << "Количество цехов: " << t.ammountceh << endl;
    cout << "Количество рабочих цехов: " << t.ammountcehwork << endl;
    cout << "Показатель: " << t.index << endl;
    return out;
}
istream& operator >> (istream& in, ks& t)
{
    cout << "Введите название:";
    cin.ignore(1, '\n');
    getline(cin, t.name);
    cout << "Введите количество цехов: ";
    t.ammountceh = checking(0,1000, "Введите количество цехов: ");
    cout << "Введите количество работающих цехов: ";
    t.ammountcehwork = checking(0,t.ammountceh, "Введите количество работающих цехов: ");
    cout << "Введите показатель:";
    t.index = checking(0, 1, "Введите показатель:");
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