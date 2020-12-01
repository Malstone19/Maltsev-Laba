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
    cin >> t.name;
    checking(t.ammountceh, "Введите количество цехов:");
    do
    {
        checking(t.ammountcehwork, "Введите количество работающих цехов:");
    } while (t.ammountcehwork > t.ammountceh);
    checking(t.index, "Введите показатель:");
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