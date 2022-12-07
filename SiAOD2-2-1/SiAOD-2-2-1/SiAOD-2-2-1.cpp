#include "Funcs.h"

int main()
{
    setlocale(0, "");
    cout << "Введите имя текстового файла\n";
    string filename;
    cin >> filename;
CHOOSE:
    cout << "\nВведите номер функции\n\n";
    cout << "1.Создание текстового файла кодировки ASCII, содержащего десятичные числа по несколько чисел на строке\n";
    cout << "2.Вывод содержимого текстового файла\n";
    cout << "3.Добавление новой строки в конец файла\n";
    cout << "4.Прочитать значение числа, указав его порядковый номер в файле, и вернуть его значение\n";
    cout << "5.Определить количество чисел в файле\n";
    cout << "6.Создать два новых файла из значений исходного...\n";
    cout << "0.Выйти из программы\n";
    unsigned int choose;
    bool func_res;
    cin >> choose;
    cout << endl;

    switch (choose)
    {
    case 1:
    {
        func_res = generate(filename);
        if (!func_res)
        {
            cout << "\nНу ты лох\n";
            exit(1);
        }
        break;
    }
    case 2:
    {
        func_res = print(filename);
        if (!func_res)
        {
            cout << "\nНу ты лох\n";
            exit(2);
        }
        break;
    }
    case 3:
    {
        string text;
        cout << "Введите строку для добавления в конец файла\n";
        cin.clear();
        cin.ignore();
        getline(cin, text);
        func_res = append(filename,text);
        if (!func_res)
        {
            cout << "\nНу ты лох\n";
            exit(3);
        }
        break;
    }
    case 4:
    {
        unsigned int n;
    INPUT4:
        cin.clear();
        cin.ignore();
        cout << "Введите порядковый номер числа\n";
        if (!(cin >> n)) goto INPUT4;
        int result = search(filename,n);
        if (!result)
        {
            cout << "\nНу ты лох\n";
            exit(4);
        }
        else cout << result << endl;
        break;
    }
    case 5:
    {
        func_res = count(filename);
        if (!func_res)
        {
            cout << "\nНу ты лох\n";
            exit(5);
        }
        break;
    }
    case 6:
    {
        func_res = merge(filename);
        if (!func_res)
        {
            cout << "\nНу ты лох\n";
            exit(6);
        }
        break;
    }
    case 0:
    {
        exit(0);
        break;
    }
    }

    goto CHOOSE;
}