#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int* m = new int(50);
	float* n = new float();
	cout << "m指向的数值是: " <<*m<< endl;
	delete m;
	*n = 0.5;
	cout << "n指向的数值是: " << *n << endl;
	delete n;
}














