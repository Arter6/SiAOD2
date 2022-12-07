#include "Funcs.h"

bool generate(string filename)
{
    ofstream A(filename);
    if (!A.is_open())
    {
        cout << "Ошибка при открытии файла\n";
        A.close();
        return false;
    }
    for (int i = 0; i < rand() % 10 + 1; i++)
    {
        if (i) A << '\n';
        for (int j = 0; j < rand() % 7 + 1; j++)
        {
            A << rand() % 100 + 3 << " ";
        }
    }
    if (A.bad())
    {
        cout << "Ошибка инпута\n";
        A.close();
        return false;
    }
    A.close();
    return true;
}

bool print(string filename)
{
    ifstream A(filename);
    if (!A.is_open())
    {
        cout << "Ошибка при открытии файла\n";
        A.close();
        return false;
    }
    string tmp;
    while (getline(A, tmp))
    {
        cout << tmp << endl;
    }
    if (A.bad())
    {
        cout << "Ошибка аутпута\n";
        A.close();
        return false;
    }
    A.close();
    return true;
}

bool append(string filename, string text)
{
    string temp = text;
    temp.erase(remove_if(temp.begin(), temp.end(), ::isspace), temp.end());
    if (!all_of(temp.begin(), temp.end(), ::isdigit))
    {
        cout << "Это не число\n";
        return false;
    }
    ofstream A(filename, ios::app);
    if (!A.is_open())
    {
        cout << "Ошибка при открытии файла\n";
        A.close();
        return false;
    }
    A << '\n' << text;
    if (A.bad())
    {
        cout << "Ошибка инпута\n";
        A.close();
        return false;
    }
    A.close();
}

int search(string filename, unsigned int num)
{
    int k = 1,key=NULL;
    stringstream ss;
    string s;
    ifstream A(filename);
    if (A.bad())
    {
        cout << "Ошибка при открытии файла\n";
        A.close();
        return NULL;
    }
    while (getline(A, s))
    {
        ss.clear();
        ss << s;
        while (getline(ss, s, ' '))
        {
            if (k == num) key = stoi(s);
            k++;
        }
    }
    if (A.bad())
    {
        cout << "Ошибка инпута\n";
        A.close();
        return NULL;
    }
    A.close();
    return key;
}

bool count(string filename)
{
    unsigned int k = 0;
    stringstream ss;
    string s;
    ifstream A(filename);
    if (!A.is_open())
    {
        cout << "Ошибка при открытии файла\n";
        A.close();
        return false;
    }
    while (getline(A, s))
    {
        ss.clear();
        ss << s;
        while (getline(ss, s, ' '))
        {
            /*if (all_of(s.begin(), s.end(), ::isdigit))*/
                k++;
        }
    }
    cout << k << endl;
    if (A.bad())
    {
        cout << "Ошибка инпута\n";
        A.close();
        return false;
    }
    A.close();
}

bool merge(string filename)
{
    unsigned int k = 0;
    stringstream ss;
    string s;
    ifstream A(filename);
    if (!A.is_open())
    {
        cout << "Ошибка при открытии файла\n";
        A.close();
        return false;
    }
    while (getline(A, s))
    {
        ss.clear();
        ss << s;
        while (getline(ss, s, ' '))
        {
            /*if (all_of(s.begin(), s.end(), ::isdigit))*/ k++;
        }
    }
    A.clear();
    A.seekg(0, A.beg);
    fstream B("B.txt", ios::out);
    fstream C("C.txt", ios::out);
    unsigned int m = 1;
    while (getline(A, s))
    {
        ss.clear();
        ss << s;
        while (getline(ss, s, ' '))
        {
            /*if (all_of(s.begin(), s.end(), ::isdigit))
            {
                if (m <= (k + 1) / 2)
                {
                    B << s << " ";
                }
                else
                {
                    C << s << " ";
                }
            }*/

            if (m <= (k + 1) / 2)
            {
                B << s << " ";
            }
            else
            {
                C << s << " ";
            }
            m++;
        }
    }
    A.close();
    B.close();
    C.close();
    ofstream A_(filename);
    ifstream B_("B.txt");
    ifstream C_("C.txt");
    string s_B, s_C;
    while (getline(B_, s_B, ' ') and getline(C_, s_C, ' '))
    {
        if (stoi(s_B) < stoi(s_C))
        {
            A_ << s_B << " " << s_C << " ";
        }
        else
        {
            A_ << s_C << " " << s_B << " ";
        }
    }
    if (A_.bad())
    {
        cout << "Ошибка инпута\n";
        A_.close();
        return false;
    }
    A_.close();
    B_.close();
    C_.close();
}