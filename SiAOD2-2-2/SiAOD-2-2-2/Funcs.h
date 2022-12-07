#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

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
        return to_string(car_number) + "\n" + string(name) + "\n" + string(car_name) + "\n" + string(date) + "\n" + string(site) + "\n" + string(section) + "\n" + to_string(fee) + "\n";
    }
};
#pragma pack(pop)

bool TtoB(string);
bool BtoT(string);
bool print(string);
bool search(string, unsigned int);
bool remove(string, int);
bool violation(string,unsigned int);
bool doubleFee(string, char[11], char[9]);