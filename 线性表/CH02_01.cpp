#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int Score[5] = {87,60,90,65,70};
	int sum = 0;

	for (int i=0;i<5;i++)
	{
		cout << "第"<<i<<"位学生的分数："<<Score[i] << endl;
		sum +=Score[i];
	}
	cout << "总和为: " << sum << endl;
    return 0;
}

