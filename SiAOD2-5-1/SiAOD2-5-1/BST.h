#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

struct BST
{
	int key;
	int pos;
	BST* left;
	BST* right;

	BST(int key, int pos, BST* left = nullptr, BST* right = nullptr);
	~BST();
	//BST* insert(BST* root, int key, int pos);
	//BST* search(BST* root, int key);
	//void print2DUtil(BST* root, int delim);
	//void print2D();
};

BST* BSTinsert(BST* root, int key, int pos);
BST* BSTdeleteNode(BST* root, int key);
BST* BSTminValueNode(BST* root);
BST* BSTsearch(BST* root, int key);