#include "stdafx.h"
#include<iostream>
#include <string>
using namespace std;

class student_list
{
public:
	int number;
	string name;
	int score;
	class student_list *next;
};

int main()
{
	student_list* students = new student_list;
	student_list* ptr = new student_list();
	auto* deptr = new student_list();
	ptr = students;
	cout << "请输入5位学生的数据:" << endl;
	cout << "请输入座号: " << "\t";
	cin >> students->number;
	cout << students->number << endl;
	cout << "请输入姓名: " << "\t";
	cin >> students->name;
	cout << students->name << endl;
	cout << "请输入成绩: " << "\t";
	cin >> students->score;
	cout << students->score << endl;
	for (int i=1;i<5;i++)
	{
		students->next = new student_list;
		cout << "请输入座号: " <<"\t";
		cin >> students->next->number;
		cout << students->next->number << endl;
		cout << "请输入姓名: " << "\t";
		cin >> students->next->name;
		cout << students->next->name<<endl;
		cout << "请输入成绩: " << "\t";
		cin >> students->next->score;
		cout << students->next->score<<endl;
		students = students->next;
	}
	while (ptr != NULL)
	{
		cout << ptr->number << "  " << ptr->name << "  " << ptr->score << endl;;
		deptr = ptr;
		ptr = ptr->next;
		delete deptr;
	}
}















