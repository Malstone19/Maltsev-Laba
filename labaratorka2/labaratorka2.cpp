// Maltsev Aleksey laba1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<fstream>
#include <vector>
#include <string>
#include "truba.h"
#include "utils.h"
#include "ks.h"

using namespace std;

void zamena(truba& pipe1)
{
    checking(pipe1.repair, "Ремонт: ");
}


/*void filetruba(ofstream& outf, const truba& pipe1)
{
    outf << "Труба" << endl;
    outf << "Индетификатор трубы: " << pipe1.id << endl;
    outf << "Длина трубы: " << pipe1.dlina << endl;
    outf << "Диаметр трубы: " << pipe1.diam << endl;
    outf << "Ремонт?: " << pipe1.repair << endl;
}

void fileks(ofstream& outf, const ks& ks1)
{
    outf << endl;
    outf << "Компрессорная станция" << endl;
    outf << "Индетификатор КС: " << ks1.id << endl;
    outf << "Название КС: " << ks1.name << endl;
    outf << "Количество цехов: " << ks1.ammountceh << endl;
    outf << "Количество рабочих цехов: " << ks1.ammountcehwork << endl;
    outf << "Показатель: " << ks1.index << endl;
}*/


void redakt(ks& ks1)
{
    cout << "Если хотите добавить работающий цех - нажмите 1; если хотите отнять - нажмите 0" << endl;
    int x;
    cin >> x;
    if (x == 1)
    {
        if (ks1.ammountcehwork + 1 > 0 && ks1.ammountcehwork + 1 <= ks1.ammountceh)
        {
            ks1.ammountcehwork++;
            cout << "Сделано" << endl;
        }
        else
        {
            cout << "Нельзя сделать" << endl;
        }
    }
    else
    {
        if (x == 0)
        {
            if (ks1.ammountcehwork - 1 >= 0 && ks1.ammountcehwork - 1 < ks1.ammountceh)
            {
                ks1.ammountcehwork--;
                cout << "Сделано" << endl;
            }
            else
            {
                cout << "Ошибка" << endl;;
            }
        }
    }
}


/*truba izfiletruba(ifstream& fin)
{
    truba pipe1;
    fin >> pipe1.id >> pipe1.dlina >> pipe1.diam >> pipe1.repair;
    return pipe1;
}

ks izfileks(ifstream& fin)
{
    ks ks1;
    fin >> ks1.id >> ks1.name >> ks1.ammountceh >> ks1.ammountcehwork >> ks1.index;
    return ks1;
}*/



void print_menu()
{
    system("cls");
    cout << "1. Добавить трубу" << endl;
    cout << "2. Добавить КС" << endl;
    cout << "3. Просмотр всех объектов" << endl;
    cout << "4. Редактировать трубу" << endl;
    cout << "5. Редактировать КС" << endl;
    cout << "6. Сохранить трубы" << endl;
    cout << "7. Загрузить трубы" << endl;
    cout << "8. Удалить трубу" << endl;
    cout << "9. Удалить КС" << endl;
    cout << "10. Поиск трубы по фильтру" << endl;
    cout << "11. Поиск КС по имени" << endl;
    cout << "12. Поиск по проценту" << endl;
    cout << "13. Сохранить КС" << endl;
    cout << "14. Загрузить КС" << endl;
    cout << "0. Выход" << endl;
    cout << "Введите команду: ";
}

int GetCorrectNumber(int left, int right)
{
    int x;
    while (((cin >> x)).fail() || x<left || x>right)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Ошибка при вводе" << endl << "Введите команду: ";
    }
    return x;
}

string file_name()
{
    string name_file;
    cout << "Введите название файла: ";
    cin.ignore(1, '\n');
    getline(cin, name_file);
    return name_file;
}


truba& SelectPipe(vector<truba>& g)
{
    cout << "Введите индекс трубы: ";
    unsigned int indexi = GetCorrectNumber(1u, g.size());
    return g[indexi - 1];
}

ks& SelectKs(vector<ks>& l)
{
    cout << "Введите индекс КС: ";
    unsigned int indexi = GetCorrectNumber(1u, l.size());
    return l[indexi - 1];
}

void DeletePipe(vector<truba>& t)
{
    cout << "Введите индекс трубы: ";
    unsigned int indexi = GetCorrectNumber(1u, t.size());
    t.erase(t.begin() + indexi - 1);
}

void DeleteKs(vector<ks>& d)
{
    cout << "Введите индекс КС: ";
    unsigned int indexi = GetCorrectNumber(1u, d.size());
    d.erase(d.begin() + indexi - 1);
}

vector<int> filterpipe(vector<truba>& t)
{
    cout << "1 - в ремонте, 0 - не в ремонте" << endl;
    int a;
    cin >> a;
    vector<int> result;
    for (int i = 0; i < t.size(); i++)
    {
        if (t[i].repair == a)
        {
            result.push_back(i);
        }
    }
    return result;
}

vector<int> ksfiltername(vector<ks>& t)
{
    cout << "Введите название: ";
    vector<int> result;
    string b;
    cin >> b;
    for (int i = 0; i < t.size(); i++) 
    {
        if (t[i].name == b)
        {
            result.push_back(i);
        }
    }
    return result;
}

vector<int> ksfilterpercent(vector<ks>& t)
{
    cout << "Введите процент: ";
    vector<int> result;
    float c;
    cin >> c;
    for (int i = 0; i < t.size(); i++)
    {
        float f;
        f = (((float)t[i].ammountceh - (float)t[i].ammountcehwork) / (float)t[i].ammountceh) * 100;
        if ( abs(f - c) <= 1 )
        {
            result.push_back(i);
        }
    }
    return result;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    vector <truba> pipes;
    vector <ks> kss;
    while (true)
    {
        print_menu();
        switch (GetCorrectNumber(0, 14))
        {
        case 0:
        {
            return 0;
        }
        case 1:
        {
            truba pipe1;
            cin >> pipe1;
            pipes.push_back(pipe1);
            break;
        }
        case 2:
        {
            ks ks1;
            cin >> ks1;
            kss.push_back(ks1);
            break;
        }
        case 3:
        {
            for (auto& pipe1 : pipes)
                cout << pipe1;
            for (auto& ks1 : kss)
                cout << ks1;
            system("pause");
            break;
        }
        case 4:
        {
            if (pipes.size() > 0)
            {
                zamena(SelectPipe(pipes));
                system("pause");
                break;
            }
            else
            {
                cout << "Вы не ввели трубы" << endl;
                system("pause");
                break;
            }
            
        }
        case 5:
        {
            if (kss.size() > 0)
            {
                redakt(SelectKs(kss));
                system("pause");
                break;
            }
            else
            {
                cout << "Вы не ввели КС" << endl;
                system("pause");
                break;
            }  
        }
        case 6:
        {
            ofstream outf;
            outf.open(file_name(), ios::out);
            if (outf.is_open())
            {
                outf << pipes.size();
                for (truba pipe1 : pipes)
                    outf << pipe1;
                outf.close();
            }
            system("pause");
            break;
        }
        case 7:
        {
            ifstream fin;
            fin.open(file_name(), ios::in);
            if (fin.is_open())
            {
                int countpipe;
                fin >> countpipe;
                pipes.resize(countpipe);
                for (truba& pipe1 : pipes)
                    fin >> pipe1;
                fin.close();
            }
            system("pause");
            break;
        }
        case 8:
        {
            if (pipes.size() > 0) 
            {
                DeletePipe(pipes);
                break;
            }
            else
            {
                cout << "Вы не ввели трубы" << endl;
                system("pause");
                break;
            }
           
        }
        case 9:
        {
            if (kss.size() > 0)
            {
                DeleteKs(kss);
                break;
            }
            else
            {
                cout << "Вы не ввели КС" << endl;
                system("pause");
                break;
            }
        }
        case 10:
        { 
            if (pipes.size() > 0)
            {
                auto index = filterpipe(pipes);
                for (int i = 0; i < index.size(); i++)
                {
                    cout << pipes[index[i]] << endl;
                }
                system("pause");
                break;
            }
            else
            {
                cout << "Вы не ввели трубы" << endl;
                system("pause");
                break;
            }
        }
        case 11:
        {
            if (kss.size() > 0)
            {
                auto ind = ksfiltername(kss);
                for (int i = 0; i < ind.size(); i++)
                {
                    cout << kss[ind[i]] << endl;
                }
                system("pause");
                break;
            }
            else
            {
                cout << "Вы не ввели КС" << endl;
                system("pause");
                break;
            }
        }
        case 12:
        {
            if (kss.size() > 0)
            {
                auto indd = ksfilterpercent(kss);
                for (int i = 0; i < indd.size(); i++)
                {
                    cout << kss[indd[i]] << endl;
                }
                system("pause");
                break;
            }
            else
            {
                cout << "Вы не ввели КС" << endl;
                system("pause");
                break;
            }           
        }
        case 13:
        {
            ofstream outf;
            outf.open(file_name(), ios::out);
            if (outf.is_open())
            {
                outf << kss.size();
                for (ks ks1 : kss)
                    outf << ks1;
                outf.close();
            }
            system("pause");
            break;
        }
        case 14:
        {
            ifstream fin;
            fin.open(file_name(), ios::in);
            if (fin.is_open())
            {
                int countks;
                fin >> countks;
                kss.resize(countks);
                for (ks& ks1 : kss)
                    fin >> ks1;
                fin.close();
            }
            system("pause");
            break;
        }
        }




    }

}
