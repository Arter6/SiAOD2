#include "graph.h"

#define infinity INT_MAX

void graph::add(int v1, int v2, int weight)
{
	if (v1 <= 0 or v2 <= 0) return;

	if (max(v1, v2) > adj.size())
	{
		adj.resize(max(v1, v2));
	}

	for (auto x : adj[v1 - 1])
	{
		if (x.node == v2) return;
	}

	adj[v1 - 1].push_back(arc(v2, weight));
}

void graph::print()
{
	for (int i = 0; i < adj.size(); i++)
	{
		for (int j = 0; j < adj[i].size(); j++)
		{
			cout << "{" << i + 1 << "," << adj[i][j].node << "," << (adj[i][j].weight==infinity? "INF" : to_string(adj[i][j].weight)) << "}  ";
		}
		cout << endl;
	}
}

void graph::floyd()
{
	int n = adj.size();
	vector<vector<int>> matrix(n,vector<int>(n,infinity));
	path = vector<vector<int>>(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
	{
		matrix[i][i] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < adj[i].size(); j++)
		{
			matrix[i][adj[i][j].node - 1] = adj[i][j].weight;
		}
	}

	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << (matrix[i][j]==infinity? "INF" : to_string(matrix[i][j])) << " ";
		}
		cout << endl;
	}*/

	/*cout << "____________________________________________________\n\n";*/

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if ((long long)matrix[i][k] + (long long)matrix[k][j] < matrix[i][j])
				{
					matrix[i][j] = matrix[i][k] + matrix[k][j];
					path[i][j] = k+1;
				}
			}
		}
	}

	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << (matrix[i][j] == infinity ? "INF" : to_string(matrix[i][j])) << " ";
		}
		cout << endl;
	}*/

	cout << "____________________________________________________\n\n";
}

void graph::printPath(int v1, int v2)
{
	int k = path[v1-1][v2-1];
	if (k == 0) return;
	printPath(v1, k);
	cout << k << " ";
	printPath(k, v2);
}