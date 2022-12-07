#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

struct ST
{
	int key;
	int pos;
	ST* left;
	ST* right;
	static int rotateCount;
	static int insertCount;

	ST(int key, int pos, ST* left = nullptr, ST* right = nullptr);
	~ST();
};

ST* rightRotate(ST* x);
ST* leftRotate(ST* x);
ST* splay(ST* root,int key);
ST* STinsert(ST* root, int key, int pos);
ST* STdeleteNode(ST* root, int key);
ST* STsearch(ST* root, int key);