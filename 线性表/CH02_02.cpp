#include "stdafx.h"
#include <iostream>
using namespace std;

class half_sum
{
public:
	int half_sum1=0;
	int half_sum2=0;
	int half_sum3=0;
};

class Month_sum
{
public:
	int January=0;
	int February=0;
	int March=0;
	int April=0;
	int May=0;
	int June=0;
};

int main()
{
	int stuff[6][3] = { {112,90,108},{76,120,99},{95,88,126},{120,112,90},{98,108,76},{68,120,98} };

	half_sum stuff_half_sum ;
	Month_sum month_sum;
	for (int i=0;i<6;i++)
	{
		stuff_half_sum.half_sum1 += stuff[i][0];
		stuff_half_sum.half_sum2 += stuff[i][1];
		stuff_half_sum.half_sum3 += stuff[i][2];
	}
	for (int j = 0; j < 3; j++)
	{
		month_sum.January += stuff[0][j];
		month_sum.February += stuff[1][j];
		month_sum.March += stuff[2][j];
		month_sum.April += stuff[3][j];
		month_sum.May += stuff[4][j];
		month_sum.June += stuff[5][j];
	}
	cout << "销售员1前半年销售总金额为：" <<stuff_half_sum.half_sum1<< endl;
	cout << "销售员2前半年销售总金额为：" << stuff_half_sum.half_sum2 << endl;
	cout << "销售员3前半年销售总金额为：" << stuff_half_sum.half_sum3 << endl;
	cout << "所有销售员1月的销售总金额为：" << month_sum.January << endl;
	cout << "所有销售员2月的销售总金额为：" << month_sum.February << endl;
	cout << "所有销售员3月的销售总金额为：" << month_sum.March << endl;
	cout << "所有销售员4月的销售总金额为：" << month_sum.April << endl;
	cout << "所有销售员5月的销售总金额为：" << month_sum.May << endl;
	cout << "所有销售员6月的销售总金额为：" << month_sum.June << endl;
	return 0;
}