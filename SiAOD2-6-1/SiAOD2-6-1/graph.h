#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <string>
using namespace std;

struct arc
{
	int node;
	int weight;

	arc(int node_, int weight_) :node(node_), weight(weight_) {};
};

struct graph
{
	vector<vector<arc>> adj;
	vector<vector<int>> path;

	void add(int, int, int);
	void print();
	void floyd();
	void printPath(int,int);
};