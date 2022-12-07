#include "Funcs.h"

bool TtoB(string filename)
{
	ofstream A(filename, ios::binary);
	ifstream B("1.txt");
	if (!B)
	{
		cout << "Ошибка при открытии файла\n";
		A.close();
		B.close();
		return false;
	}
	PDD a;
	string s;
	int k = 0;
	while (getline(B, s))
	{
		switch (k % 7)
		{
		case 0:
		{
			/*strcpy_s(a.car_number, s.c_str());*/
			a.car_number = stoi(s);
			break;
		}
		case 1:
		{
			strcpy_s(a.name, s.c_str());
			break;
		}
		case 2:
		{
			strcpy_s(a.car_name, s.c_str());
			break;
		}
		case 3:
		{
			strcpy_s(a.date, s.c_str());
			break;
		}
		case 4:
		{
			strcpy_s(a.site, s.c_str());
			break;
		}
		case 5:
		{
			strcpy_s(a.section, s.c_str());
			break;
		}
		case 6:
		{
			//strcpy_s(a.fee, s.c_str());
			a.fee = stoi(s);
			break;
		}
		}
		if ((k + 1) % 7 == 0)
		{
			A.write((char*)&a, sizeof(PDD));
		}
		k++;
		//B >> a.car_number >> a.name >> a.car_name >> a.date >> a.site >> a.section >> a.fee;

		//a.fee = 1;
		//cout << a.print();
		//A.write((char*)&a, sizeof(PDD));
	}
	/*strcpy_s(a.car_number, "111111");
	strncpy_s(a.name, "aaaaaaaaaaaaaaa",15);
	strncpy_s(a.car_name, "bbbbbbbbbb",10);
	strncpy_s(a.date, "30.09.2022",10);
	strncpy_s(a.site, "sitesitesitesit",15);
	strncpy_s(a.section, "10.10.10",8);
	strncpy_s(a.fee, "999",3);
	A.write((char*)&a, sizeof(PDD));*/
	if (A.bad() or B.bad())
	{
		cout << "Ошибка инпута\n";
		A.close();
		B.close();
		return false;
	}
	A.close();
	B.close();
	return true;
}

bool BtoT(string filename)
{
	ifstream A(filename, ios::binary);
	ofstream B("1.txt");
	if (!A)
	{
		cout << "Ошибка при открытии файла\n";
		A.close();
		B.close();
		return false;
	}
	//A.seekg(0, A.end);
	//int A_length = A.tellg();
	//A.seekg(0, A.beg);
	PDD a;
	for (int i = 0; A.read((char*)&a, sizeof(PDD)); i++)
	{
		if (i)
		{
			/*cout << "\n";*/
			B << "\n";
		}
		/*cout << a.print();
		cout << "\n";*/
		B << a.print();
		//<< a.name << a.car_name << a.date << a.site << a.section << a.fee;
	}
	if (A.bad() or B.bad())
	{
		cout << "Ошибка аутпута\n";
		A.close();
		B.close();
		return false;
	}
	A.close();
	B.close();
	return true;
}

bool BRead(string filename)
{
	ifstream A(filename, ios::binary);
	if (!A.is_open())
	{
		cout << "Ошибка при открытии файла\n";
		A.close();
		return false;
	}
	//A.seekg(0, A.end);
	//int A_length = A.tellg();
	//A.seekg(0, A.beg);
	PDD a;
	while (A.read((char*)&a, sizeof(PDD)))
	{
		cout << a.print() << endl;
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

bool BDirSearch(string filename, unsigned int num)
{
	ifstream A(filename, ios::binary);
	if (!A)
	{
		cout << "Ошибка при открытии файла\n";
		A.close();
		return false;
	}
	A.seekg(0, A.end);
	unsigned int A_length = A.tellg();
	A.seekg(0, A.beg);
	if (num > A_length / sizeof(PDD))
	{
		cout << "В файле нет столько записей\n";
		return false;
	}
	PDD a;
	A.seekg((num - 1) * sizeof(PDD));
	A.read((char*)&a, sizeof(PDD));
	cout << endl << a.print() << endl;
	if (A.bad())
	{
		cout << "Ошибка инпута\n";
		A.close();
		return false;
	}
	A.close();
}

bool BDelete(string filename, int car_number)
{
	fstream A(filename, ios::binary | ios::in | ios::out);
	if (!A)
	{
		cout << "Ошибка при открытии файла\n";
		A.close();
		return false;
	}
	PDD a, a_end;
	A.seekg(-((int)sizeof(PDD)), A.end);
	A.read((char*)&a_end, sizeof(PDD));
	A.seekg(0, A.beg);
	while (A.read((char*)&a, sizeof(PDD)))
	{
		if (a.car_number == car_number)
		{
			A.seekg(-(int(sizeof(PDD))), A.cur);
			A.write((char*)&a_end, sizeof(PDD));
			A.seekg(sizeof(PDD), A.cur);
		}
	}
	cout << endl << a.print() << endl;
	if (A.bad())
	{
		cout << "Ошибка инпута\n";
		A.close();
		return false;
	}
	A.close();
	return true;
}

bool f6(string filename)
{
	ifstream A(filename, ios::binary);
	if (!A.is_open())
	{
		cout << "Ошибка при открытии файла\n";
		A.close();
		return false;
	}
	//A.seekg(0, A.end);
	//int A_length = A.tellg();
	//A.seekg(0, A.beg);
	PDD a;
	int i = 0;
	while (A.read((char*)&a, sizeof(PDD)))
	{
		//cout << a.print() << endl;
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

bool small_file(string filename, int amount)
{
	ofstream A(filename, ios::binary);
	if (!A.is_open())
	{
		cout << "Ошибка при открытии файла\n";
		A.close();
		return false;
	}
	PDD a;


	char alphabit[] =
		"0123456789"
		"QWERTYUIOPLKJHGFDSAZXCVBNM"
		"qwertyuioplkjhgfdsazxcvbnm";


	string s;
	for (int i = 0; i < amount; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			switch (j)
			{

			case 0:
			{
				a.car_number = rand() % 100000;
				break;
			}
			case 1:
			{
				for (int k = 0; k < 7; k++)
				{
					s += alphabit[rand() % (sizeof(alphabit) - 1)];
				}
				strcpy_s(a.name, s.c_str());
				s = "";
				break;
			}
			case 2:
			{
				//s = to_string((char)(rand() % 128)) + to_string((char)(rand() % 128)) + to_string((char)(rand() % 128)) + to_string((char)(rand() % 128)) + to_string((char)(rand() % 128)) + to_string((char)(rand() % 128)) + to_string((char)(rand() % 128));
				for (int k = 0; k < 7; k++)
				{
					s += alphabit[rand() % (sizeof(alphabit) - 1)];
				}
				strcpy_s(a.car_name, s.c_str());
				s = "";
				break;
			}
			case 3:
			{
				//s = to_string((char)(rand() % 128)) + to_string((char)(rand() % 128)) + to_string((char)(rand() % 128)) + to_string((char)(rand() % 128)) + to_string((char)(rand() % 128)) + to_string((char)(rand() % 128)) + to_string((char)(rand() % 128));
				for (int k = 0; k < 7; k++)
				{
					s += alphabit[rand() % (sizeof(alphabit) - 1)];
				}
				strcpy_s(a.date, s.c_str());
				s = "";
				break;
			}
			case 4:
			{
				//s = to_string((char)(rand() % 128)) + to_string((char)(rand() % 128)) + to_string((char)(rand() % 128)) + to_string((char)(rand() % 128)) + to_string((char)(rand() % 128)) + to_string((char)(rand() % 128)) + to_string((char)(rand() % 128));
				for (int k = 0; k < 7; k++)
				{
					s += alphabit[rand() % (sizeof(alphabit) - 1)];
				}
				strcpy_s(a.site, s.c_str());
				s = "";
				break;
			}
			case 5:
			{
				//s = to_string((char)(rand() % 128)) + to_string((char)(rand() % 128)) + to_string((char)(rand() % 128)) + to_string((char)(rand() % 128)) + to_string((char)(rand() % 128)) + to_string((char)(rand() % 128)) + to_string((char)(rand() % 128));
				for (int k = 0; k < 7; k++)
				{
					s += alphabit[rand() % (sizeof(alphabit) - 1)];
				}
				strcpy_s(a.section, s.c_str());
				s = "";
				break;
			}
			case 6:
			{
				a.fee = rand() % 100000;
				break;
			}

			}
		}

		A.write((char*)&a, sizeof(PDD));
	}
}