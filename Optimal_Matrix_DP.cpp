﻿
#include "stdafx.h"
#include <iostream>

using namespace std;

int Optimal_Matrix(int matrices, int** mt, int ** vt, int * P) //method that will print out the optimal matrix
{
	int min; //this is a variable which will store the minimum number of multiplications 

	for (int b = 1; b < matrices; b++)  
	{
		for (int i = 1; i < matrices - b + 1; i++) 
		{
			int j = i + b;
			int temp;
			int k = i;
			min = mt[i][k] + mt[k + 1][j] + P[i - 1] * P[k] * P[j];  //this is from the notes, it finds the products obtained according to the optimal order 
	
			for (; k < j; k++) 
			{	
				temp = mt[i][k] + mt[k + 1][j] + P[i - 1] * P[k] * P[j]; //stores the current number of multiplications 
				if (temp < min) //compares the current to the original minimum cost
				{
					min = temp; //if temp is smaller than min then you can change min to equal temp, bc it is the new lowest number
				}
			}

			mt[i][j] = min; //bc we are using dynamic programming we need to store the minimum cost so that we don't repeated 
			vt[i][j] = k;
		}
	}

	return min; //returns the value of min which will tell us the optimal number
}

int main()
{
	int matrices = 2; //hardcoded set of matrices 
	int dim_table[] = {2, 2, 2}; //hardcoded area which holds the dimensions of the matrix

	int ** multi_table = new int *[matrices + 1]; //declaring a double pointer which will hold the number of multiplications 
	for (int i = 0; i < matrices + 1; i++) //for loop to fill the empty matrix
	{
		multi_table[i] = new int[matrices + 1]; 
		for (int j = 0; j < matrices + 1; j++)
		{
			multi_table[i][j] = 0; //this makes sure that the matrix is zero'd out so it does not affect the end number
		}
	}

	int ** value_table = new int *[matrices + 1]; //declaring a double pointer which will hold the compinations of numbers we already multiplied 
	for (int i = 0; i < matrices + 1; i++) //for loop to fill the empty matrix
	{
		value_table[i] = new int[matrices + 1];
		for (int j = 0; j < matrices + 1; j++)
		{
			value_table[i][j] = 0; //this makes sure that the matrix is zero'd out so it does not affect the end number
		}
	}

	printf ("The Optimal number of multiplications: %d", Optimal_Matrix(matrices, multi_table, value_table, dim_table)); //final output will be 2 thing: the optimal number of multiplications the algorithm did 
	cout << endl; 

    return 0;
}
