﻿// Maltsev Aleksey laba1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<fstream>
#include <vector>
#include <string>
#include "truba.h"
#include "utils.h"
#include "ks.h"
#include <unordered_map>

using namespace std;
struct paraks
{
    int idks;
    float idpipe;
};

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
    cout << "15. Вывод графа тест" << endl;
    cout << "16. тут должна быть сортировка" << endl;
    cout << "17. Вывод в файл" << endl;
    cout << "18. Загрузка из файла" << endl;
    cout << "0. Выход" << endl;
    cout << "Введите команду: ";
}


string file_name()
{
    string name_file;
    cout << "Введите название файла: ";
    cin.ignore(1, '\n');
    getline(cin, name_file);
    return name_file;
}

template<typename PC, typename T>
using Filter = bool(*)(PC& pc, T param);

bool Checkname(ks& ks1, string param)
{
    return ks1.Get_Name() == param;
}

bool Checkrepair(truba& pipe1, bool repair)
{
    return pipe1.GetRepair() == repair;
}

bool Checkks(ks& ks1, float percent)
{
    return abs(percent - ((float)(ks1.Get_ammountceh() - (float)ks1.Get_ammountcehwork()) / (float)ks1.Get_ammountceh() * 100))<1e-6;
}


template<typename PC, typename T>
vector<int> FindPipeOrKs(unordered_map<int, PC>& pc, Filter<PC, T> f, T param)
{
    vector <int> res;
    res.reserve(pc.size());
    for (auto& pipeorks : pc)
    {
        if (f(pipeorks.second, param))
            res.push_back(pipeorks.first);
    }
    return res;
}


void DeletePipe(unordered_map<int, truba>& t)
{
    cout << "Введите индекс трубы: ";
    unsigned int indexi = checking(1u, t.size(), "Введите индекс трубы: ");
    t.erase(t.find(indexi));
}

void DeleteKs(unordered_map<int, ks>& d)
{
    cout << "Введите индекс КС: ";
    unsigned int indexi = checking(1u, d.size(), "Введите индекс КС: ");
    d.erase(d.find(indexi));
}


//https://e-maxx.ru/algo/topological_sort
void dfs(int v, unordered_map<int, vector<paraks>>& g, unordered_map<int, bool>& count, vector<int>& answer) {
    count[v] = true;
    vector<paraks> array;
    if (g.find(v) != g.end()) {

        array = g[v];
        for (auto& element : array) {
            int to = element.idks;

            if (!count[to])
                dfs(to, g, count, answer);
        }
    }
    answer.push_back(v);
}
//https://e-maxx.ru/algo/finding_cycle
bool dfs2(int v, unordered_map<int, vector<paraks>>& g, unordered_map<int, int>& cl, int& cycle_st) {
    if (g.find(v) == g.end())
    {
        return false;
    }
    cl[v] = 1;
    for (size_t i = 0; i < g[v].size(); ++i) {
        int to;

        to = g[v][i].idks;
        if (cl[to] == 0) {
            if (dfs2(to, g, cl, cycle_st))  return true;
        }
        else if (cl[to] == 1) {
            cycle_st = to;
            return true;
        }
    }
    cl[v] = 2;
    return false;
}

unordered_map<int, int> visitedks(unordered_map<int, vector<paraks>>& g)
{
    unordered_map<int, int> countArr;
    for (auto& element : g)
    {
        countArr[element.first] = 0;
        for (auto& p : element.second)
        {
            countArr[p.idks] = 0;
        }
    }
    return countArr;
}

bool searchcycle(unordered_map<int, vector<paraks>>& g)
{
    unordered_map<int, int> p;
    int cycle_st, cycle_end;
    p = visitedks(g);
    cycle_st = -1;
    for (auto& element : p)
        if (dfs2(element.first, g, p, cycle_st)) break;
    if (cycle_st == -1) return false;
    else return true;
}


unordered_map<int, bool> usedks(unordered_map<int, vector<paraks>>& g)
{
    unordered_map<int, bool> countArr;
    for (auto& element : g)
    {
        countArr[element.first] = false;
        for (auto& p : element.second)
        {
            countArr[p.idks] = false;
        }
    }
    return countArr;
}

void topsort(unordered_map<int, vector<paraks>>& g, unordered_map<int, bool>& count, vector<int>& answer) {
    count = usedks(g);

    answer.clear();
    for (auto& element : count)
        if (!element.second)
            dfs(element.first, g, count, answer);
    reverse(answer.begin(), answer.end());
}



void Vgraph(unordered_map<int, vector<paraks>>& graph, unordered_map<int, ks>& kss, unordered_map<int, truba>& pipes, int indexpipe, int indexks1, int indexks2)
{
    paraks p;
    p.idpipe = indexpipe;
    p.idks = indexks2;
    graph[indexks1].push_back(p);
}

void vivodgraph(unordered_map<int, vector<paraks>>& graph, unordered_map<int, ks>& kss, unordered_map<int, truba>& pipes)
{
    for (auto& element : graph)
    {
        cout << "КС с ID " << element.first << " соединен с КС'ми ID: ";
        for (auto ks = element.second.begin(); ks != element.second.end(); ks++)
        {
            cout << ks->idks << " трубой длиной " << pipes[ks->idpipe].dlina;
            if (ks + 1 != element.second.end()) cout << ", ";
        }
        cout << endl;
    }
}

void gtofile(unordered_map<int, vector<paraks>> g)
{

    ofstream fout;
    fout.open(file_name(), ios::out);
    if (!fout.is_open())
        cout << "Файл не может быть открыт!" << endl;
    else
    {

        for (auto& element : g)
        {
            fout << element.second.size() << " ";
            fout << element.first << " ";
            for (auto ks = element.second.begin(); ks != element.second.end(); ks++)
            {
                fout << ks->idks << " " << ks->idpipe << " ";
            }
            fout << endl;
        }
        cout << "Вывели в файл данные" << endl;
        fout.close();
    }
}



void gfromfile(unordered_map<int, vector<paraks>>& g)
{

    ifstream fin(file_name(), ios::out);
    if (!fin.is_open())
        cout << "Файл не может быть открыт!" << endl;
    else
    {
        int buff;
        while (fin >> buff)
        {
            int ksid1;
            fin >> ksid1;
            for (int i = 0; i < buff; i++)
            {
                int ksid2;
                fin >> ksid2;
                int pipeid;
                fin >> pipeid;
                paraks pair1;
                pair1.idks = ksid2;
                pair1.idpipe = pipeid;
                g[ksid1].push_back(pair1);
            }
        }
        cout << "Ввели из файла данные" << endl;
        fin.close();
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    unordered_map<int, truba> pipes;
    unordered_map<int, ks> kss;
    unordered_map<int, vector<paraks>> g;
    while (true)
    {
        print_menu();
        switch (checking(0, 18, "Введите команду: "))
        {
        case 0:
        {
            return 0;
        }
        case 1:
        {
            truba pipe1;
            cin >> pipe1;
            pipes.insert(pair<int, truba>(pipe1.GetId(),pipe1));
            break;
        }
        case 2:
        {
            ks ks1;
            cin >> ks1;
            kss.insert(pair<int, ks>(ks1.GetId(), ks1));
            break;
        }
        case 3:
        {
            if (pipes.size() > 0)
                for (auto iter = pipes.begin(); iter != pipes.end(); ++iter)
                {
                    cout << iter->second;
                }
            else cout << endl << "Вы забыли ввести данные трубы!" << endl;;

            if (kss.size() > 0)
                for (auto iter = kss.begin(); iter != kss.end(); ++iter)
                {
                    cout << iter->second;
                }
            else cout << endl << "Вы забыли ввести данные КС!" << endl;;
            system("Pause");
            break;
        }
        case 4:
        {
            unordered_map <int, truba>::iterator number;
            if (pipes.size() > 0)
            {
                cout << "Введите ID трубы: ";
                unsigned index = checking(1u, truba::GetMaxID(), "Введите ID трубы: ");
                number = pipes.find(index);
                number->second.editing_pipe();
            }
            else cout << "Вы забыли ввести данные трубы!" << endl;;
            system("Pause");
            break;           
        }
        case 5:
        {
            unordered_map <int, ks>::iterator number;
            if (kss.size() > 0)
            {
                cout << "Введите ID КС: ";
                unsigned index = checking(1u, ks::GetMaxID(), "Введите ID КС: ");
                number = kss.find(index);
                number->second.editing_ks();
            }
            else cout << "Вы забыли ввести данные КС!" << endl;
            system("Pause");
            break;
        }
        case 6:
        {
            ofstream fout;
            fout.open(file_name(), ios::out);
            if (fout.is_open())
            {
                if (pipes.size() > 0)
                {
                    fout << pipes.size() << endl;
                    for (auto iter = pipes.begin(); iter != pipes.end(); ++iter)
                        fout << iter->second;
                }
                else cout << "Вы забыли ввести данные для труб!" << endl;;
                fout.close();
            }
            else cout << "Файл не открыт" << endl;
            system("Pause");
            break;
        }
        case 7:
        {
            ifstream fin;
            fin.open(file_name(), ios::in);
            if (fin.is_open())
            {
                pipes.erase(pipes.begin(), pipes.end());
                int count;
                fin >> count;
                for (int i = 1; i <= count; ++i)
                {
                    truba pipe1;
                    fin >> pipe1;
                    pipes.insert(pair<int, truba>(pipe1.GetId(), pipe1));
                }
                fin.close();
            }
            else cout << "Файл не открыт" << endl;
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
            bool number;
            cout << "В ремонте? 1 или 0: ";
            number = checking(0, 1, "В ремонте? 1 или 0: ");
            if (pipes.size() != 0)
            {
                for (int i : FindPipeOrKs(pipes, Checkrepair, number))
                    cout << pipes[i];
            }
            else cout << "Забыли добавить трубы" << endl;
            system("pause");
            break;
        }
        case 11:
        {
            string name;
            cout << "Введите название КС для поиска: ";
            cin.ignore(1, '\n');
            getline(cin, name);
            if (kss.size() != 0)
            {
                for (int i : FindPipeOrKs(kss, Checkname, name))
                    cout << kss[i];
            }
            else cout << "Забыли добавить КС" << endl;
            system("pause");
            break;
        }
        case 12:
        {
            float percent;
            cout << "Введите процент незадействованных КС для поиска:";
            cin >> percent;
            if (kss.size() != 0)
            {

                for (int i : FindPipeOrKs(kss, Checkks, percent))
                    cout << kss[i];
            }
            else cout << "Забыли добавить КС" << endl;
            system("pause");
            break;
        }
        case 13:
        {
            ofstream fout;
            fout.open(file_name(), ios::out);
            if (fout.is_open())
            {
                if (kss.size() > 0)
                {
                    fout << kss.size() << endl;
                    for (auto iter = kss.begin(); iter != kss.end(); ++iter)
                        fout << iter->second;
                }
                else cout << "Вы забыли ввести данные для КС!" << endl;
                fout.close();
            }
            else cout << "Файл не открыт" << endl;
            system("Pause");
            break;
        }
        case 14:
        {
            ifstream fin;
            fin.open(file_name(), ios::in);
            if (fin.is_open())
            {
                kss.erase(kss.begin(), kss.end());
                int count;
                fin >> count;
                for (int i = 1; i <= count; ++i)
                {
                    ks ks1;
                    fin >> ks1;
                    kss.insert(pair<int, ks>(ks1.GetId(), ks1));
                }

                fin.close();
            }
            else cout << "Файл не открыт" << endl;
            break;
        }
        case 16:
        {
            if (!searchcycle(g))
            {
                unordered_map<int, bool> count;
                vector<int> answer;
                topsort(g, count, answer);
                for (auto i = answer.begin(); i != answer.end(); i++)
                {
                    cout << *i;
                    if (i + 1 != answer.end()) cout << " , ";
                }
                cout << endl;
                system("pause");
            }
            else
            {
                cout << "Граф цикличный";
            }
            system("pause");
            break;
        }
        case 15:
        {
            unordered_map<int, bool> usedpipes;

            for (auto& element : pipes)
            {
                usedpipes.insert(make_pair(element.first, false));
            }

            g.clear();
            int time, indexpipe, indexks1, indexks2; 
            cout << "Сколько раз введете КС и трубу?";
            time = checking(0, 200,"Сколько раз введете КС и трубу?");
            while (time--)
            {
                cout << "Введите индекс трубы ";
                indexpipe = checking(0, 200, "Введите индекс трубы ");
                while (usedpipes[indexpipe]) {
                    cout << "Уже использовали" << endl;
                    cout << "Введите индекс трубы ";
                    indexpipe = checking(0, 200, "Введите индекс трубы ");
                }
                usedpipes[indexpipe] = true;
                cout << "Введите индекс КС1, от которой ";
                indexks1 = checking(0, 200, "Введите индекс КС1, от которой ");
                cout << "Введите индекс КС2, к которой ";
                indexks2 = checking(0,200, "Введите индекс КС2, к которой ");
                Vgraph(g, kss, pipes, indexpipe, indexks1, indexks2);
            }
            vivodgraph(g,kss,pipes);
            system("pause");
            break;
        }
        case 17:
        {
            gtofile(g);
            system("pause");
            break;
        }
        case 18:
        {
            gfromfile(g);
            system("pause");
            break;
        }
        }




    }

}
