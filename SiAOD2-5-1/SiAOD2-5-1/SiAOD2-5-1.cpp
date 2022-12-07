#include "Funcs.h"
#include "ctime"

int main()
{
	setlocale(0, "");
	//srand(time(NULL));
	string filename = "test.txt";
	small_file(filename, 10);
	BRead(filename);
	cout << endl << endl;
	/*BST* root=new BST(NULL,NULL);
	root=BSTRead(filename, root);
	root->print2D();
	root=deleteNode(root, 26299);
	root->print2D();*/
	BST* BSTroot = new BST(NULL, NULL);
	ST* STroot = new ST(NULL, NULL);
	int choose;
CHOOSE:
	cout << "\n1.Бинарное дерево поиска\n";
	cout << "2.Косое дерево\n";
	cout << "0.Выход из программы\n";
	cout << "Введите номер опции: ";
	cin >> choose;
	switch (choose)
	{
	case 1:
	{
		CHOOSE1:
		cout << "\n1.Считывание дерева из файла\n";
		cout << "2.Вывод дерева\n";
		cout << "3.Удаление элемента по ключу\n";
		cout << "4.Поиск элемента по ключу\n";
		cout << "5.Вернуться назад\n";
		cout << "Введите номер опции: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			BSTroot = BSTRead(filename, BSTroot);
			break;
		}
		case 2:
		{
			BSTprint2D(BSTroot, -10);
			cout << "\n\n________________________________________________________\n\n";
			break;
		}
		case 3:
		{
			int key;
			cout << "Введите ключ: ";
			cin >> key;
			BSTroot = BSTdeleteNode(BSTroot, key);
			cout << "\n\n________________________________________________________\n\n";
			break;
		}
		case 4:
		{
			int key;
			cout << "Введите ключ: ";
			cin >> key;
			BSTroot = BSTsearch(BSTroot, key);
			cout << BSTroot->key << " " << BSTroot->pos;
			cout << "\n\n________________________________________________________\n\n";
			break;
		}
		case 5:
		{
			goto CHOOSE;
			break;
		}
		}
		goto CHOOSE1;
		break;
	}
	case 2:
	{
		CHOOSE2:
		cout << "\n1.Считывание дерева из файла\n";
		cout << "2.Вывод дерева\n";
		cout << "3.Удаление элемента по ключу\n";
		cout << "4.Поиск элемента по ключу\n";
		cout << "5.Вернуться назад\n";
		cout << "Введите номер опции: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			STroot = STRead(filename, STroot);
			cout << "Среднее число поворотов: " << (float)ST::rotateCount / ST::insertCount << endl;
			break;
		}
		case 2:
		{
			STprint2D(STroot, -10);
			cout << "\n\n________________________________________________________\n\n";
			break;
		}
		case 3:
		{
			int key;
			cout << "Введите ключ: ";
			cin >> key;
			STroot = STdeleteNode(STroot, key);
			cout << "\n\n________________________________________________________\n\n";
			break;
		}
		case 4:
		{
			int key;
			cout << "Введите ключ: ";
			cin >> key;
			STroot = STsearch(STroot, key);
			cout << STroot->key << " " << STroot->pos;
			cout << "\n\n________________________________________________________\n\n";
			break;
		}
		case 5:
		{
			goto CHOOSE;
		}
		}
		goto CHOOSE2;
		break;
	}
	case 0:
	{
		delete BSTroot;
		delete STroot;
		exit(0);
		break;
	}
	}
	goto CHOOSE;
}