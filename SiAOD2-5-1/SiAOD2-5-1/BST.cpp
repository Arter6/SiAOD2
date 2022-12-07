#include "BST.h"

BST::BST(int key, int pos, BST* left, BST* right)
{
	this->key = key;
	this->pos = pos;
	this->left = left;
	this->right = right;
}

BST::~BST()
{
	delete left;
	delete right;
}

BST* BSTinsert(BST* root, int key, int pos)
{
	if (!root or root->key == NULL)
	{
		return new BST(key, pos);
	}

	if (key > root->key)
	{
		root->right = BSTinsert(root->right, key, pos);
	}

	else if (key < root->key)
	{
		root->left = BSTinsert(root->left, key, pos);
	}

	return root;
}

BST* BSTsearch(BST* root, int key)
{
	if (root == nullptr or root->key == key)
	{
		return root;
	}

	if (root->key < key)
	{
		return BSTsearch(root->right, key);
	}

	return BSTsearch(root->left, key);
}

BST* BSTminValueNode(BST* root)
{
	BST* current = root;
	while (current->left)
	{
		current = current->left;
	}
	return current;
}

BST* BSTdeleteNode(BST* root, int key)
{
	if (!root) return root;

	if (key < root->key)
	{
		root->left = BSTdeleteNode(root->left, key);
	}
	else if (key > root->key)
	{
		root->right = BSTdeleteNode(root->right, key);
	}
	else
	{
		if (!root->left and !root->right)
		{
			return nullptr;
		}
		else if (!root->left)
		{
			BST* temp = root->right;
			free(root);
			return temp;
		}
		else if (!root->right)
		{
			BST* temp = root->left;
			free(root);
			return temp;
		}

		BST* temp = BSTminValueNode(root->right);
		root->key = temp->key;
		root->pos = temp->pos;
		root->right = BSTdeleteNode(root->right, temp->key);
	}

	return root;
}