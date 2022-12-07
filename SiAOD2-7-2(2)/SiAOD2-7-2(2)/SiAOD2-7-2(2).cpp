#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Node
{
	int pos;
	char next;

	Node(int pos, char next)
	{
		this->pos = pos;
		this->next = next;
	}
};

int findMatch(map<string, int>& book, string s)
{
	map<string, int>::iterator pos;
	pos = book.find(s);

	if (pos != book.end())
		return pos->second;

	return -1;
}

vector<Node> encodeLZ78(string s)
{
	int i, j, pos, k, temp;
	char next;
	vector<Node> array;
	string buffer = "";
	map<string, int> book = {};
	for (pos = 0; pos < s.length();)
	{
		i = 0;
		temp = -1;
		do
		{
			k = temp;
			temp = findMatch(book, s.substr(pos, ++i));
		} while (temp != -1);
		next = pos + i - 1 < s.length() ? s.at(pos + i - 1) : '\0';
		if (k == -1)
		{
			array.push_back(Node(0, next));
		}
		else
		{
			array.push_back(Node(k, next));
		}
		book.insert({ s.substr(pos,i),book.size() + 1 });
		pos += i;
	}
	return array;
}

string decodeLZ78(vector<Node> array)
{
	vector<string> book = { "" };
	string res = "",word;
	for (Node x : array)
	{
		word = book[x.pos] + x.next;
		res += word;
		book.push_back(word);
	}
	return res;
}

int main()
{
	string s="abacababacabc";
	s = "sarsalsarsanlasanl";
	string res;
	vector<Node> array = encodeLZ78(s);
	for (int i = 0; i < array.size(); i++)
	{
		cout << "<" + to_string(array[i].pos) + "," + array[i].next + ">\n";
	}
	res = decodeLZ78(array);
	cout << res;
}