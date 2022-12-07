#pragma once
#include "BST.h"
#include "ST.h"

#pragma pack(push,1)
struct PDD
{
    int car_number;
    char name[16];
    char car_name[11];
    char date[11];
    char site[16];
    char section[9];
    int fee;

    string print()
    {
        return to_string(car_number) + "\n" + string(name) + "\n" + string(car_name) + "\n" + string(date) + "\n" + string(site) + "\n" + string(section) + "\n" + to_string(fee);
    }
};
#pragma pack(pop)

bool TtoB(string);
bool BtoT(string);
bool BRead(string);
bool BDirSearch(string, unsigned int);
bool BDelete(string, int);
BST* BSTRead(string,BST*);
ST* STRead(string, ST*);
bool small_file(string, int);
void BSTprint2D(BST* root, int delim);
void STprint2D(ST* root, int delim);