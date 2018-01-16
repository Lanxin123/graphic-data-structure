#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int A[4][4] = { {1,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,4} };
	int A_t[4][4];
	for (int i=0;i<4;i++)
	{
		for (int j=0;j<4;j++)
		{
			A_t[i][j] = A[j][i];
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << A_t[i][j]<<" ";
		}
		cout << endl;
	}

	

}
















