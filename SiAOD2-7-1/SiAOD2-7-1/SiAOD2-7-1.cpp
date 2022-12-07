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
	int sizeBefore = 0, n=0,sizeAfter=0;
	string str = "aaaa3444   rrr";
	cout << str.length()*sizeof(str[0]);
	cout << endl << endl;
	string* str_array = toRLE(str,n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < str_array[i].length(); j++)
		{
			cout << sizeof(str_array[i][j])<<" ";
		}
	}
	delete[] str_array;
}