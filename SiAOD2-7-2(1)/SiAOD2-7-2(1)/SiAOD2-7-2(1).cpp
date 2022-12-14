#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define window_size 15

struct Node
{
	int offset;
	int length;
	char next;

	Node(int offset, int length, char next)
	{
		this->offset = offset;
		this->length = length;
		this->next = next;
	}
};

int findMatch(const string window, const string str)
{
	int j, k, pos;

	if (window.length() == 0) return -1;

	for (int i = 0; i < window.length(); i++)
	{
		pos = i;
		k = 0;

		for (j = 0; j < str.length(); j++)
		{
			if (str[j] == window[i + k % (window.length() - i)])
				k++;
			else
				break;
		}
		if (j == str.length())
			return pos;
	}

	return -1;
}

vector<Node> encodeLZ77(string s)
{
	vector<Node> array;
	string window = "",temp_str;
	int pos = 0, windowPos, i, temp;
	char next;
	while (pos < s.length())
	{
		i = 0;
		temp = -1;
		do
		{
			windowPos = temp;
			temp = findMatch(window, s.substr(pos, ++i));
		} while (temp != -1 and pos + i - 1 < s.length());
		next = pos + i - 1 < s.length() ? s.at(pos + i - 1) : '\0';
		if (windowPos == -1)
		{
			array.push_back(Node(0, i - 1, next));
		}
		else
		{
			array.push_back(Node(window.length() - windowPos, i - 1, next));
		}
		temp_str = window + s.substr(pos,i);
		window = temp_str.substr(max((int)(temp_str.length() - window_size), 0));
		pos += i;
	}
	return array;
}

string decodeLZ77(vector<Node> array)
{
	string res = "";
	int start;
	for (Node x : array)
	{
		if (x.length > 0)
		{
			start = res.length() - x.offset;
			for (int i = 0; i < x.length; i++)
			{
				res += res[start + i];
			}
		}
		res += x.next;
	}
	return res;
}

int main()
{
	setlocale(0, "");
	int sizeBefore, sizeAfter=0;
	string str = "abacabacabadaca";
	str = "010110110110100010001";
	str = "hellolololololowwwlolololololololololo";
	sizeBefore = str.length();
	cout << "Байт до кодирования: " << sizeBefore<<endl;
	vector<Node> array;
	array = encodeLZ77(str);
	cout << "Закодированная строка (каждый узел с новой строки):\n";
	for (int i = 0; i < array.size(); i++)
	{
		int temp = sizeof(int) + sizeof(int) + sizeof(char); // Числа хранятся в 4 байтах, если уменьшить до 1 (в следующей строке), ограничивая окно, то лучше будет
		//temp = 1 + 1 + sizeof(char);
		sizeAfter += temp;
		cout << "<" + to_string(array[i].offset) + "," + to_string(array[i].length) + "," + array[i].next + ">  " + to_string(temp) << " Байт" << endl;
	}
	cout << "Байт после кодирования: " << sizeAfter << endl;
	string res = decodeLZ77(array);
	cout << "Раскодированная строка: "<<res<<endl;
	cout << "Коэффициент: " << (double)sizeBefore / sizeAfter;
}