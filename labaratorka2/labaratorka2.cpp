// Maltsev Aleksey laba1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
/*struct paraks
{
    int id;
    float ves;
};*/

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
    return percent > ((ks1.Get_ammountceh() - ks1.Get_ammountcehwork()) / ks1.Get_ammountceh() * 100);
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


/*https://e-maxx.ru/algo/topological_sort
void dfs(int v, unordered_map<int, vector<paraks>>& g, unordered_map<int, bool>& count, vector<int>& ans) {
    count[v] = true;
    vector<paraks> arr;
    arr = g[v];
    for (auto& vershina : arr) {
        int to = vershina.id;
        if (!count[to])
            dfs(to, g, count, ans);
    }
    ans.push_back(v);
}
unordered_map<int, bool> usedks(unordered_map<int, vector<paraks>>& g)
{
    unordered_map<int, bool> usedArr;
    for (auto& vershina : g)
    {
        usedArr[vershina.first] = false;
        for (auto& p1 : vershina.second)
        {
            usedArr[p1.id] = false;
        }
    }
    return usedArr;
}
void topsort(unordered_map<int, vector<paraks>>& g, unordered_map<int, bool>& count, vector<int>& ans) {
    count = usedks(g);

    ans.clear();
    for (auto& vershina : count)
        if (!vershina.second)
            dfs(vershina.first, g, count, ans);
    reverse(ans.begin(), ans.end());
}



void Vgraph(unordered_map<int, vector<paraks>>& g, vector<ks>& kss, vector<truba>& pipes, int indexpipe, int indexks1, int indexks2)
{
    paraks para;
    para.id = indexks2 - 1;
    para.ves = pipes[indexpipe - 1].dlina;
    g[indexks1 - 1].push_back(para);
}

void vivodgraph(unordered_map<int, vector<paraks>>& g)
{
    for (auto& vershina : g)
    {
        cout << "Компрессорная станция " << vershina.first+1 << " соединена с: ";
        for (auto ks = vershina.second.begin(); ks != vershina.second.end(); ks++)
        {
            cout << ks->id+1 << " КС, трубой длиной " << ks->ves;
            if (ks + 1 != vershina.second.end()) cout << ", ";
        }
        cout << endl;
    }
}
*/



int main()
{
    setlocale(LC_ALL, "Russian");
    unordered_map<int, truba> pipes;
    unordered_map<int, ks> kss;
   // unordered_map<int, vector<paraks>> g;
    while (true)
    {
        print_menu();
        switch (checking(0, 16, "Введите команду: "))
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
            else cout << endl << "Вы забыли ввести данные трубы!\n";

            if (kss.size() > 0)
                for (auto iter = kss.begin(); iter != kss.end(); ++iter)
                {
                    cout << iter->second ;
                }
            else cout << endl << "Вы забыли ввести данные КС!\n";
            system("Pause");
            break;
        }
        case 4:
        {
            unordered_map <int, truba>::iterator number;
            cout << "Введите ID трубы: ";
            if (pipes.size() > 0)
            {
                cout << "Введите ID трубы: ";
                unsigned index = checking(1u, truba::GetMaxID(), "Введите ID трубы: ");
                number = pipes.find(index);
                number->second.editing_pipe();
            }
            else cout << "Вы забыли ввести данные трубы!\n";
            system("Pause");
            break;           
        }
        case 5:
        {
            unordered_map <int, ks>::iterator number;
            cout << "Введите ID КС: ";
            if (kss.size() > 0)
            {
                cout << "Введите ID КС: ";
                unsigned index = checking(1u, ks::GetMaxID(), "Введите ID КС: ");
                number = kss.find(index);
                number->second.editing_ks();
            }
            else cout << "Вы забыли ввести данные КС!\n";
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
                else cout << "Вы забыли ввести данные для труб!\n";
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
                else cout << "Вы забыли ввести данные для КС!\n";
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
           /* unordered_map<int, bool> used;
            vector<int> ans;
            topsort(g, used, ans);
            for (auto i = ans.begin(); i != ans.end(); i++)
            {
                cout << *i+1;
                if (i + 1 != ans.end()) cout << ", ";
            }
            cout << endl;
            system("pause");
            break;*/
        }
        case 15:
        {
           /* g.clear();
            int time,indexpipe, indexks1, indexks2;
            checking(time, "Сколько раз введете КС и трубу?");
            while (time--)
            {
                checking(indexpipe, "Введите индекс трубы ");
                checking(indexks1, "Введите индекс КС1, от которой ");
                checking(indexks2, "Введите индекс КС2, к которой ");
                Vgraph(g, kss, pipes, indexpipe, indexks1, indexks2);
            }
            vivodgraph(g);
            system("pause");
            break;*/
        }
        }




    }

}
