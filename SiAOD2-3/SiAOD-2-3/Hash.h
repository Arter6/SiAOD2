#pragma once

#include <list>
#include "Funcs.h"

struct HashElement
{
    int key;
    int pos;

    HashElement(int key, int pos)
    {
        this->key = key;
        this->pos = pos;
        
    }

    HashElement() {};
};

class Hash
{
private:
    int capacity;
    HashElement** table;

public:
    Hash(int c);
    ~Hash();
    void insertItem(int key, int pos);
    void deleteItem(int key);
    //int checkPrime(int n);
    //int getPrime(int n);
    int hashFunction(int key);
    void displayHash();
    void readFile(string filename);
    void resize();
    int search(int key);
};