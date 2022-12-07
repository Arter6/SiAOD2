#include "graph.h"

int main()
{
	setlocale(0, "");
	graph* G = new graph();
	int v1, v2, weight;
	cout << "Введите первую и вторую вершины, а также вес дуги через пробел\n";
	cout << "#граф ориентированный, вводите по одной дуге, для окончания введите 0\n";
	cout << "Ввод: ";
	while (true)
	{
		cin >> v1;
		if (v1 == 0) break;
		cin >> v2 >> weight;
		G->add(v1, v2, weight);
	}
	G->floyd();

	int choose;
CHOOSE:
	cout << "1.Вывести список смежности графа\n";
	cout << "2.Вывод кратчайшего пути между двумя точками\n";
	cout << "3.Выход из программы\n";
	cout << "Введите опцию: ";
	cin >> choose;
	switch (choose)
	{
	case 1:
	{
		G->print();
		break;
	}
	case 2:
	{
		cout << "Введите вершины: ";
		cin >> v1 >> v2;
		cout << v1 << " ";
		G->printPath(v1, v2);
		cout << v2;
		cout << endl;
		break;
	}
	case 3:
	{
		goto END;
		break;
	}
	}
	goto CHOOSE;
END:
	delete G;
}