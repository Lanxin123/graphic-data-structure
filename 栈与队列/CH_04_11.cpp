#include "stdafx.h"
#include <iostream>
using namespace std;
int main(void)
{
	int front, rear, val = 0, queue[5] = { 0 };
	front = rear = -1;
	while (rear < 5 && val != -1)
	{
		cout << "请输入一个值以存入队列，欲取出值请输入-2。(结束输入-1)：";
		cin >> val;
		if (val == -2)
		{
			if (front == rear)
			{
				cout << "[队列已经空了]" << endl;
				break;
			}
			front++;
			if (front == 5)
				front = 0;
			cout << "取出队列值 [" << queue[front] << "]" << endl;
			queue[front] = 0;
		}
		else if (val != -1 && rear < 5)
		{
			if (rear + 1 == front || rear == 4 && front <= 0)
			{
				cout << "[队列已经满了]" << endl;
				break;
			}
			rear++;
			if (rear == 5)
				rear = 0;	//要是我我就用取余
			queue[rear] = val;
		}
	}
	cout << "\n队列剩余数据：" << endl;
	if (front == rear)
		cout << "队列已空!!" << endl;
	else
	{
		while (front != rear)
		{
			front++;
			if (front == 5)
				front = 0;
			cout << "[" << queue[front] << "]";
			queue[front] = 0;
		}
	}
	cout << endl;
	system("pause");
	return 0;
}
