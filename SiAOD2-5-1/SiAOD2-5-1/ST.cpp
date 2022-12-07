#include "ST.h"

int ST::rotateCount = 0;
int ST::insertCount = 0;

ST::ST(int key, int pos, ST* left, ST* right)
{
	this->key = key;
	this->pos = pos;
	this->left = left;
	this->right = right;
}

ST::~ST()
{
	delete left;
	delete right;
}

ST* rightRotate(ST* x)
{
	ST::rotateCount++;
	ST* y = x->left;
	x->left = y->right;
	y->right = x;
	return y;
}

ST* leftRotate(ST* x)
{
	ST::rotateCount++;
	ST* y = x->right;
	x->right = y->left;
	y->left = x;
	return y;
}

ST* splay(ST* root, int key)
{
	if (!root or root->key == key)
	{
		return root;
	}

	if (key < root->key)
	{
		if (!root->left) return root;

		if (key < root->left->key)
		{
			root->left->left = splay(root->left->left, key);
			root = rightRotate(root);
		}
		else if (key > root->left->key)
		{
			root->left->right = splay(root->left->right, key);
			if (root->left->right) root->left = leftRotate(root->left);
		}

		return (!root->left) ? root : rightRotate(root);
	}
	else
	{
		if (!root->right) return root;

		if (key < root->right->key)
		{
			root->right->left = splay(root->right->left, key);
			if (root->right->left) root->right = rightRotate(root->right);
		}
		else if (key > root->right->key)
		{
			root->right->right = splay(root->right->right, key);
			root = leftRotate(root);
		}

		return (!root->right) ? root : leftRotate(root);
	}
}

ST* STinsert(ST* root, int key, int pos)
{
	if (!root) return new ST(key, pos);

	root = splay(root, key);
	if (root->key == key) return root;

	ST* newRoot = new ST(key, pos);
	if (key < root->key)
	{
		newRoot->right = root;
		newRoot->left = root->left;
		root->left = nullptr;
	}
	else
	{
		newRoot->left = root;
		newRoot->right = root->right;
		root->right = nullptr;
	}

	return newRoot;
}

ST* STsearch(ST* root, int key)
{
	return splay(root, key);
}

ST* STdeleteNode(ST* root, int key)
{
	if (!root) return nullptr;

	ST* temp;
	root = splay(root, key);

	if (key != root->key) return root;

	if (!root->left)
	{
		temp = root;
		root = root->right;
	}
	else
	{
		temp = root;
		root = splay(root->left, key);
		root->right = temp->right;
	}

	free(temp);

	return root;
}