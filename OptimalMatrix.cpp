

#include "pch.h"
#include <iostream>
using namespace std;

void PrintOptimal(int** kArray, int i, int j)
{
	if (i == j)
	{
		cout << "A" << i << " ";
	}
	else
	{
		cout << "(";
		PrintOptimal(kArray, i, kArray[i][j]);
		PrintOptimal(kArray, kArray[i][j] + 1, j);
		cout << ")";
	}
}

int main()
{
	int numMat;
	cout << "Welcome! This program will determine the optimal order to multiply n matrices." << endl;
	cout << "Please enter the number of matrices: ";
	cin >> numMat;

	int *p; 
	int psize = numMat + 1;
	p = new int[psize];

	cout << "Please enter the first dimension of each matrix." << endl;
	cout << "Lastly, enter the last dimension of the final matrix." << endl;
	for (int i = 0; i < psize; i++)
	{
		cout << "dimension " << i << " : ";
		cin >> p[i];
	}

	
	int **cost;
	cost = new int*[psize];  

	for (int i = 0; i < psize; i++)
	{
		cost[i] = new int[psize];
	}

	int ** kArray; // we'll be making an array to hold each split
	kArray = new int*[psize];

	for (int i = 0; i < (psize); i++)
	{
		kArray[i] = new int[psize];
	}

	for (int length = 1; length < numMat; length++)
	{
		for (int i = 1; i < numMat - length + 1; i++)
		{

			int j = i + length;
			int temp; // temporarily stores the cost
			int k = i;
			int minCost = cost[i][k] + cost[k + 1][j] + p[i - 1] * p[k] * p[j]; // stores our minimum cost
			int kay = i;
			for (; k < j; k++)
			{
				//below is our cost of multiplying being stored and compared to what we previously stored as the minimum
				temp = cost[i][k] + cost[k + 1][j] + p[i - 1] * p[k] * p[j]; //stores the current cost for each subproblem
				if (temp < minCost) // checks to see if the cost we're currently calculating is less than our current minimum cost
				{
					minCost = temp; // if our freshly calculated cost is smaller than our current minimum cost, we'll store it as the new minimum cost
					kay = k;
				}
			}

			cost[i][j] = minCost;
			kArray[i][j] = kay;
		}
	}

	cout << endl << endl;
	cout << "Optimal order of multiplying this chain: " << endl;
	PrintOptimal(kArray, 1, numMat);
	cout << endl;
	return 0;
}
