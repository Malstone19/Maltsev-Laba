// Maltsev Aleksey laba1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<fstream>
using namespace std;

struct truba
{
    bool exist = false;
    int id;
    float dlina;
    float diam;
    bool repair = false;
};

struct ks
{
    bool exist = false;
    int id;
    string name;
    int ammountceh;
    int ammountcehwork;
    float index;
};

template <typename T>

void checking(T& var, string com)
{
    do {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << com;
        cin >> var;
    } while (var < 0 || cin.fail());
}


void addks(ks& ks1)
{
    checking(ks1.id, "Введите идентификатор:");
    cout << "Введите название:";
    cin >> ks1.name;
    checking(ks1.ammountceh, "Введите количество цехов:");
    checking(ks1.ammountcehwork, "Введите количество работающих цехов:");
    checking(ks1.index, "Введите показатель:");

    ks1.exist = true;
}

void zamena(truba& pipe1)
{
    cout << "Если хотите изменить - 1; если случайно попали, то 0" << endl;
    int t; cin >> t;
    if (t == 1)
    {
        cin >> pipe1.repair;
    }


}

void file(truba pipe1, ks ks1)
{
    ofstream outf("file.txt");
    if (!outf.is_open())
    {
        cout << "Файл не может быть открыт";
    }
    else
    {

        if (pipe1.exist == true)
        {
            outf << "Труба" << endl;
            outf << "Индетификатор трубы: " << pipe1.id << endl;
            outf << "Длина трубы: " << pipe1.dlina << endl;
            outf << "Диаметр трубы: " << pipe1.diam << endl;
            outf << "Ремонт?: " << pipe1.repair << endl;
        }
        else
        {
            outf << "Труба не создана";
            cout << "Труба не создана" << endl;
        }
        if (ks1.exist == true)
        {
            outf << endl;
            outf << "Компрессорная станция" << endl;
            outf << "Индетификатор КС: " << ks1.id << endl;
            outf << "Название КС: " << ks1.name << endl;
            outf << "Количество цехов: " << ks1.ammountceh << endl;
            outf << "Количество рабочих цехов: " << ks1.ammountcehwork << endl;
            outf << "Показатель: " << ks1.index << endl;
        }
        else
        {
            outf << endl;
            outf << "Компрессорная станция не создана";
            cout << endl;
            cout << "Компрессорная станция не создана" << endl;
        }
    }
    outf.close();
}

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
        if (ks1.ammountcehwork - 1 >= 0 && ks1.ammountcehwork - 1 < ks1.ammountceh)
        {
            ks1.ammountcehwork--;
            cout << "Сделано" << endl;
        }
        else
        {
            cout << "Ошибка";
        }
    }
}

void izfile(truba& pipe1, ks& ks1)
{
    ifstream fin("in.txt");
    ks1.exist = true;
    pipe1.exist = true;
    if (!fin.is_open())
        cout << "Файл не может быть открыт";
    else
    {
        fin >> pipe1.id >> pipe1.dlina >> pipe1.diam >> pipe1.repair;
        fin >> ks1.id >> ks1.name >> ks1.ammountceh >> ks1.ammountcehwork >> ks1.index;

    }
    fin.close();
}

/*void proverka()
{
    int x;
    do {
        cin.clear();
        cin.ignore(1000, '\ n');
        cin >> x;
    } while (cin.fail());
}*/

void addpipe(truba& pipe1)
{
    checking(pipe1.id, "Введите идентификатор:");
    checking(pipe1.dlina, "Введите длину трубы:");
    checking(pipe1.diam, "Введите диаметр трубы:");
    checking(pipe1.repair, "В ремонте?:");

    pipe1.exist = true;
}

void vivodks(ks ks1)
{
    cout << endl;
    cout << "Компрессорная станция" << endl;
    cout << "Идентификатор КС: " << ks1.id << endl;
    cout << "Название КС: " << ks1.name << endl;
    cout << "Количество цехов: " << ks1.ammountceh << endl;
    cout << "Количество рабочих цехов: " << ks1.ammountcehwork << endl;
    cout << "Показатель: " << ks1.index << endl;
}

void vivodtruba(truba pipe1)
{
    cout << endl;
    cout << "Труба" << endl;
    cout << "Идентификатор трубы: " << pipe1.id << endl;
    cout << "Длина трубы: " << pipe1.dlina << endl;
    cout << "Диаметр трубы: " << pipe1.diam << endl;
    cout << "Ремонт?: " << pipe1.repair << endl;
}

void print_menu()
{
    system("cls"); // очищаем экран
    cout << "1. Добавить трубу" << endl;
    cout << "2. Добавить КС" << endl;
    cout << "3. Просмотр всех объектов" << endl;
    cout << "4. Редактировать трубу" << endl;
    cout << "5. Редактировать КС" << endl;
    cout << "6. Сохранить" << endl;
    cout << "7. Загрузить" << endl;
    cout << "0. Выход" << endl;
    cout << "Введите команду: ";
}

int GetCorrectNumber(int left, int right) //Рабочий способ, который подсказали ребята, который был в лекции
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

int main()
{
    setlocale(LC_ALL, "Russian");
    truba pipe1;
    ks ks1;
    while (true)
    {
        print_menu();
        switch (GetCorrectNumber(0, 7))
        {
        case 0:
        {
            return 0;
        }
        case 1:
        {
            addpipe(pipe1);
            break;
        }
        case 2:
        {
            addks(ks1);
            break;
        }
        case 3:
        {
            if (ks1.exist == false) { cout << "Вы не создали КС" << endl; }
            else { vivodks(ks1); }
            if (pipe1.exist == false) { cout << "Вы не создали трубу" << endl; }
            else { vivodtruba(pipe1); }
            system("pause");
            break;
        }
        case 4:
        {
            if (pipe1.exist == false) { cout << "Вы не создали трубу" << endl; }
            else
            {
                zamena(pipe1);
                system("pause");
                break;
            }
        }
        case 5:
        {
            if (ks1.exist == false) { cout << "Вы не создали КС" << endl; }
            else
            {
                redakt(ks1);
                system("pause");
                break;
            }
        }
        case 6:
        {
            file(pipe1, ks1);
            system("pause");
            break;
        }
        case 7:
        {
            izfile(pipe1, ks1);
            system("pause");
            break;
        }
        }




    }

}
