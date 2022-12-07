#include "Hash.h"

//int Hash::checkPrime(int n)
//{
//	int i;
//	if (n == 1 || n == 0)
//	{
//		return 0;
//	}
//	for (i = 2; i < n / 2; i++)
//	{
//		if (n % i == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//
//int Hash::getPrime(int n)
//{
//	if (n % 2 == 0)
//	{
//		n++;
//	}
//	while (!checkPrime(n))
//	{
//		n += 2;
//	}
//	return n;
//}

void Hash::resize()
{
	HashElement** temp = new HashElement*[capacity * 2];
	for (int i = 0; i < capacity; i++)
	{
		temp[i] = table[i];
	}
	//delete[] table;
	table = temp;
	capacity *= 2;
}


Hash::Hash(int c)
{
	//int size = getPrime(c);
	this->capacity = c;
	table = new HashElement*[capacity]();
}

Hash::~Hash()
{
	delete[] table;
}

int Hash::hashFunction(int key)
{
	//return (key % capacity);
	return ((7*key)/13 + 13)%capacity;
}

void Hash::insertItem(int key, int pos)
{
	int index = hashFunction(key);
	while (index<capacity and table[index]!=nullptr and table[index]->pos!=-1) index++;
	if (index == capacity) resize();
	table[index] = new HashElement(key,pos);
}

void Hash::deleteItem(int key)
{
	int index = hashFunction(key);
	while (index < capacity and table[index]!=nullptr and table[index]->key != key) index++;
	if (index == capacity or table[index] == nullptr or table[index]->pos==-1) return;
	/*delete table[index];*/
	/*while (index < capacity - 1 and table[index + 1] != nullptr)
	{
		table[index] = table[index + 1];
		index++;
	}*/
	table[index]->pos = -1;
	/*if (index == capacity - 1) delete table[index];*/
}

int Hash::search(int key)
{
	int index = hashFunction(key);
	while (index < capacity and table[index]!=nullptr and table[index]->key != key) index++;
	if (index == capacity or table[index] == nullptr or table[index]->pos==-1) return NULL;
	return table[index]->pos;
}

void Hash::displayHash()
{
	for (int i = 0; i < capacity; i++)
	{
		if (table[i]!=nullptr and table[i]->pos!=-1)
		{
			cout << "table[" << i << "]\n\n";
			cout << table[i]->key << endl << endl;
			cout << endl << "---------------------------------" << endl;
		}
	}
}

void Hash::readFile(string filename)
{
	ifstream A(filename, ios::binary);
	PDD a;
	//HashElement b;
	int i = 0;
	while (A.read((char*)&a, sizeof(PDD)))
	{
		i++;
		insertItem(a.car_number, i);
	}
	A.close();
}