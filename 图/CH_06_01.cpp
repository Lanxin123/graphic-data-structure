#include "stdafx.h"
#include <iostream>
using namespace std;
int main(void)
{
	int arr[6][6] = {0};//声明矩阵arr
	int data[14][2] = { { 1,2 },{ 2,1 },{ 1,5 },{ 5,1 }, //图形各边的起点值和终点值
	{ 2,3 },{ 3,2 },{ 2,4 },{ 4,2 },
	{ 3,4 },{ 4,3 },{ 3,5 },{ 5,3 },
	{ 4,5 },{ 5,4 } };
	for (int i = 0; i < 14; i++)//读取图形数据
		for (int j = 0; j < 6; j++)//填入arr矩阵
			for (int k = 0; k < 6; k++)
			{
				int tmpi, tmpj;
				tmpi = data[i][0];//tmpi为起始顶点
				tmpj = data[i][1];//tmpj为终止顶点
				arr[tmpi][tmpj] = 1;//有边的点填入1
			}
	cout << "无向图矩阵：" << endl;
	for (int i = 1; i < 6; i++)
	{
		for (int j = 1; j < 6; j++)
			cout << "[" << arr[i][j] << "] ";  //打印矩阵内容
		cout << endl;
	}
	system("pause");
}


