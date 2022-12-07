#include "Funcs.h"

int main()
{
    setlocale(0, "");
    cout << "Введите имя текстового файла\n";
    string filename;
    cin >> filename;
CHOOSE:
    cout << "\nВведите номер функции\n\n";
    cout << "1.Преобразование текстовых данных из текстового файла в двоичный файл\n";
    cout << "2.Преобразование данных из двоичного файла в текстовый\n";
    cout << "3.Вывод всех записей двоичного файла\n";
    cout << "4.Доступ к записи по её порядковому номеру в файле, используя механизм прямого доступа к записи в двоичном файле\n";
    cout << "5.Удаление записи с заданным значением ключа, выполнить путём замены на последнюю запись\n";
    cout << "6.Сформировать список нарушений по автомобилю заданного номера\n";
    cout << "0.Выйти из программы\n";
    unsigned int choose;
    bool func_res;
    cin >> choose;
    cout << endl;

    switch (choose)
    {
    case 1:
    {
        func_res = TtoB(filename);
        if (!func_res)
        {
            cout << "\nНу ты лох\n";
            exit(1);
        }
        break;
    }
    case 2:
    {
        func_res = BtoT(filename);
        if (!func_res)
        {
            cout << "\nНу ты лох\n";
            exit(2);
        }
        break;
    }
    case 3:
    {
        func_res = print(filename);
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
        cout << "Введите порядковый номер записи\n";
        if (!(cin >> n)) goto INPUT4;
        func_res = search(filename, n);
        if (!func_res)
        {
            cout << "\nНу ты лох\n";
            exit(4);
        }
        break;
    }
    case 5:
    {
        string s;
        int car_number;
        cout << "Введите номер автомобиля\n";
        cin >> car_number;
        func_res = remove(filename,car_number);
        if (!func_res)
        {
            cout << "\nНу ты лох\n";
            exit(5);
        }
        break;
    }
    case 6:
    {
        int car_number;
        cout << "Введите номер автомобиля\n";
        cin >> car_number;
        func_res = violation(filename,car_number);
        if (!func_res)
        {
            cout << "\nНу ты лох\n";
            exit(6);
        }
        break;
    }
    case 7:
    {
        string date_s, section_s;
        char date[11],section[9];
        cout << "Введите дату: ";
        cin >> date_s;
        cout << "Введите статью: ";
        cin >> section_s;
        strcpy_s(date, date_s.c_str());
        strcpy_s(section, section_s.c_str());
        func_res = doubleFee(filename, date, section);
        if (!func_res)
        {
            cout << "\nНу ты лох\n";
            exit(7);
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