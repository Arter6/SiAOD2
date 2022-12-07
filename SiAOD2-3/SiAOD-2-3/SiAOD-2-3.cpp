#include "Hash.h"

int main()
{
	setlocale(0, "");
	/*string filename = "test.txt";
	int size;
	cin >> size;
	Hash hashTable(size);
	hashTable.readFile(filename);
	hashTable.displayHash();*/

	string filename = "test.txt";
	int size = 100;
	int choose;
	Hash hashTable(size);
CHOOSE:
	cout << "Тестирование хеш-таблицы на небольшом наборе записей в двоичном файле\n";
	cout << "1. Добавление всех записей из текстового файла в двоичный\n";
	cout << "2. Создание небольшого двоичного файла записей\n";
	cout << "3. Добавление всех записей из двоичного файла в хеш-таблицу\n";
	cout << "4. Поиск записи по ключу при помощи хеш-таблицы\n";
	cout << "5. Удаление записи по ключу в хеш-таблице\n";
	cout << "6. Вывод хеш-таблицы\n";
	cout << "7. Выход\n";
	cout << "Введите номер действия: ";
	cin >> choose;
	switch (choose)
	{

	case 1:
	{
		TtoB(filename);
		break;
	}
	case 2:
	{
		cout << "Введите кол-во записей для генерации: ";
		int amount;
		cin >> amount;
		small_file(filename,amount);
		break;
	}
	case 3:
	{
		hashTable.readFile(filename);
		break;
	}
	case 4:
	{
		cout << "Введите ключ: ";
		int key, index;
		cin >> key;
		index = hashTable.search(key);
		BDirSearch(filename, index);
		break;
	}
	case 5:
	{
		cout << "Введите ключ: ";
		int key;
		cin >> key;
		hashTable.deleteItem(key);
		break;
	}
	case 6:
	{
		hashTable.displayHash();
		break;
	}
	case 7:
	{
		exit(0);
	}

	}

	goto CHOOSE;



	/*small_file(filename);
	hashTable.readFile(filename);
	f2(filename);
	hashTable.displayHash();*/
}