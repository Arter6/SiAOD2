#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string dectobin(unsigned int x)
{
    string s = "";
    unsigned int mask = (1 << 31);
    for (int i = 1; i <= 32; i++)
    {
        s+=to_string((x & mask) >> (32 - i));
        mask = mask >> 1;
    }
    return s;
}

unsigned int f1()
{
    unsigned int x = 0x5146AFC2;
    unsigned int mask = 0x0000000F;
    x = x | mask;
    return x;
}

unsigned int f2(unsigned int x)
{
    unsigned int mask = 0x00000828;
    mask = ~mask;
    x = x & mask;
    return x;
}

unsigned int f3(unsigned int x)
{
    x = x << 4;
    return x;
}

unsigned int f4(unsigned int x)
{
    x = x >> 4;
    return x;
}

unsigned int f5(unsigned int x,unsigned int n)
{
    unsigned int mask = (0x80000000>>(31-n));
    x = x | mask;
    return x;
}

void print(unsigned int x)
{
    cout << setw(4) << x << " = " << setw(sizeof(int) * 8) << dectobin(x) << endl;
}

int main()
{
    setlocale(0, "");
    cout << setiosflags(ios::left);
    cout << "Введите номер упражнения\n\n";
    cout << "1.Установить четыре младшие бита в значение 1\n";
    cout << "2.Обнулить 3-ий, 5-ый и 11-ый биты\n";
    cout << "3.Умножить число на 16\n";
    cout << "4.Поделить число на 16\n";
    cout << "5.Установить n-ый бит в значение 1\n";
    unsigned int choose, x;
    cin >> choose;
    switch (choose)
    {
    case 1:
        /*cout << "Число до установки четырёх младших битов в значение 1: " << 0x5146AFC4<<" (в двоичной: "<<dectobin(0x5146AFC4)<<")\n";
        x=f1();
        cout << "Число после: " << x << " (в двоичной: " << dectobin(x) << ")";*/
        cout << "\nЧисло до:\n";
        print(0x5146AFC4);
        x = f1();
        cout << "Число после:\n";
        print(x);
        break;
    case 2:
        cout << "Введите число\n";
        cin >> x;
        cin.clear();
        cout << "\nЧисло до:\n";
        print(x);
        x=f2(x);
        cout << "Число после:\n";
        print(x);
        break;
    case 3:
        cout << "Введите число\n";
        cin >> x;
        cin.clear();
        cout << "\nЧисло до:\n";
        print(x);
        x = f3(x);
        cout << "Число после:\n";
        print(x);
        break;
    case 4:
        cout << "Введите число\n";
        cin >> x;
        cin.clear();
        cout << "\nЧисло до:\n";
        print(x);
        x = f4(x);
        cout << "Число после:\n";
        print(x);
        break;
    case 5:
        cout << "Введите число\n";
        cin >> x;
        cin.clear();
        cout << "Введите номер бита, который необходимо установить в значение 1\n";
        unsigned int n;
        cin >> n;
        cout << "\nЧисло до:\n";
        print(x);
        x = f5(x,n);
        cout << "Число после:\n";
        print(x);
        break;
    }
}