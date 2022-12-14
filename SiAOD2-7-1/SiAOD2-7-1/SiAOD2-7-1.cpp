#include <iostream>
#include <string>
using namespace std;

string* toRLE(string str,int& n)
{
	int counter = 0;
	for (int i = 1; i < str.length(); i++)
	{
		if (str[i - 1] != str[i]) counter++;
	}
	string* str_array = new string[++counter];
	n = counter;
	counter = 0;
	int j;
	for (int i = 0; i < str.length();)
	{
		for (j = i; j < str.length() and str[i] == str[j]; j++);
		int n = j - i;
		if (n > 1)
		{
			str_array[counter++] += to_string(n) + "|" + str[i];
		}
		else
		{
			str_array[counter++] += str[i];
		}
		i = j;
	}
	return str_array;
}

int main()
{
	setlocale(0, "");
	string str;
	int sizeBefore, n=0,sizeAfter=0;
	int choose;
	cout << "1.Повторяющиеся символы\n";
	cout << "2.Неповторяющиеся символы\n";
	cout << "Ввод: ";
	cin >> choose;
	switch (choose)
	{
	case 1:
	{
		str = "aaaaaaaaa54532sddsadgggggggggggggg";
		cout << "Изначальная строка: " << str<<endl;
		break;
	}
	case 2:
	{
		str = "asdfghjkuyrqxvbn";
		cout << "Изначальная строка: " << str << endl;
		break;
	}
	}
	sizeBefore = str.length() * sizeof(str[0]);
	cout << "Байт до кодирования: "<< sizeBefore<<endl;
	string* str_array = toRLE(str,n);
	cout << "Закодированная строка: ";
	for (int i = 0; i < n; i++)
	{
		cout << str_array[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < str_array[i].length(); j++)
		{
			sizeAfter+=sizeof(str_array[i][j]);
		}
	}
	cout <<"Байт после кодирования: "<< sizeAfter<<endl;
	cout << "Коэффициент: " << (double)sizeBefore / sizeAfter;
	delete[] str_array;
}