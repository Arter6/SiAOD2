#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <cmath>
using namespace std;

struct Node
{
	char c;
	int freq;
	Node* left, * right;

	Node(char c, int freq, Node* left = nullptr, Node* right = nullptr)
	{
		this->c = c;
		this->freq = freq;
		this->left = left;
		this->right = right;
	}

	~Node()
	{
		delete left;
		delete right;
	}
};

struct Compare
{
	bool operator() (Node* left, Node* right)
	{
		return left->freq > right->freq;
	}
};

void encodeHuffman(Node* root, unordered_map<char, string>& code, string s = "")
{
	if (root == nullptr) return;

	if (!root->left and !root->right)
		code[root->c] = s;

	encodeHuffman(root->left, code, s + "0");
	encodeHuffman(root->right, code, s + "1");
}

void decodeHuffman(Node* root, int& index, string s, string& res)
{
	if (!root) return;
	if (!root->left and !root->right)
	{
		res += root->c;
		return;
	}

	if (s[++index] == '0')
	{
		decodeHuffman(root->left, index, s, res);
	}
	else
	{
		decodeHuffman(root->right, index, s, res);
	}
}

Node* huffmanTree(string s, unordered_map<char, string>& code)
{
	unordered_map<char, int> freq;
	for (char c : s)
	{
		freq[c]++;
	}

	priority_queue<Node*, vector<Node*>, Compare> pq;
	for (auto x : freq)
	{
		pq.push(new Node(x.first, x.second));
	}

	while (pq.size() != 1)
	{
		Node* left = pq.top();
		pq.pop();
		Node* right = pq.top();
		pq.pop();

		pq.push(new Node('\0', left->freq + right->freq, left, right));
	}
	Node* root = pq.top();

	encodeHuffman(root, code);

	for (auto x : code)
	{
		cout << x.first << " " << x.second << endl;
	}

	return root;
}

string encodedString(string s, unordered_map<char, string> code)
{
	string res = "";
	for (char x : s)
	{
		res += code[x];
	}
	return res;
}

string decodedString(string s, Node* root)
{
	string res = "";
	int index = -1;
	while (index < (int)s.length() - 1)
	{
		decodeHuffman(root, index, s, res);
	}
	return res;
}

int countDistinct(string s)
{
	unordered_map<char, int> m;

	for (char c : s)
	{
		m[c]++;
	}
	return m.size();
}

int main()
{
	setlocale(0, "");
	string s = "abracadabra";
	s = "Теремязев Артем Олегович"; // В моём случае коэффициент небольшой, но если добавить одну неповторяющуюся букву, всё изменится
	//s = "хТеремязев Артем Олегович";
	cout << "Бит изначально: " << s.length() * sizeof(char) * 8 << endl;
	int constLength = s.length() * ceil(log2(countDistinct(s)));
	cout << "Бит при кодировании постоянной длиной: " << constLength << endl;
	unordered_map<char, string> code;
	Node* root = huffmanTree(s, code);
	string encRes = encodedString(s, code);
	cout << "Закодированная строка (переменной длины): " << encRes << endl;
	cout << "Бит при кодировании переменной длиной: " << encRes.length() << endl;
	cout << "Коэффициент сжатия (постоянной длины): " << (double)(s.length() * sizeof(char) * 8) / constLength << endl;
	cout << "Коэффициент сжатия (переменной длины): " << (double)(s.length() * sizeof(char) * 8) / encRes.length() << endl;
	string decRes = decodedString(encRes, root);
	cout << "Раскодированная строка: " << decRes << endl;

	delete root;
}