#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	char name[4][10] = { "Justinian","Mom","Becky","Bush" };
	char* name_ptr[4] = { "Justinian","Mom","Becky","Bush" };

	for (int i=0;i<4;i++)
	{
		cout << name[i] << "\t"<<"所占地址"<<&name[i]<<endl;
	}

	for (int i=0;i<4;i++)
	{
		cout << name_ptr[i] << "\t" << "所占地址" << &name_ptr[i] << endl;
	}

}

