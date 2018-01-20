/*
[示范]:最小成本生成树
*/
#include <iostream>
#define VERTS	6 	//图的顶点数
using namespace std;
class edge        //声明边的结构
{  
	public:
	int from,to;
	int find,val;
	class edge* next;
};
typedef class edge node;
typedef node* mst;
void mintree(mst head);
mst findmincost(mst head);    
int v[VERTS+1];
int main(void)
{  
	int data[10][3]={{1,2,6},{1,6,12},
                     {1,5,10},{2,3,3},//成本表数组
                     {2,4,5},{2,6,8},{3,4,7},{4,6,11},
					 {4,5,9},{5,6,16}};
	mst head,ptr,newnode;
	head=NULL;
	cout<<"创建图的链表："<<endl;
	for(int i=0;i<10;i++)//建立图的链表
	{  
		for(int j=1;j<=VERTS;j++)
		{  
			if(data[i][0]==j)
			{  
				newnode = new node;
				newnode->from=data[i][0];
				newnode->to=data[i][1];
				newnode->val=data[i][2];
				newnode->find=0;
				newnode->next=NULL;
				if(head==NULL)
				{  
					head=newnode;
					head->next=NULL;
					ptr=head;
				}   
				else
				{  
					ptr->next=newnode;
					ptr=ptr->next;
				}
			}
		}
	}
	ptr=head;
	while(ptr!=NULL)//打印图的链表
	{  
		cout<<"起始顶点 ["<<ptr->from<<"]\t终止顶点 ["
        <<ptr->to<<"]\t路径长度 ["<<ptr->val<<"]";
		cout<<endl;
		ptr=ptr->next;
	}
	cout<<"建立最小成本生成树："<<endl;
	mintree(head); //建立最小成本生成树
	delete newnode;
	system("pause");
}
mst findmincost(mst head)//搜索成本最小的边
{
	int minval=100;
	mst ptr,retptr;
	ptr=head;
	while(ptr!=NULL)
	{
		if(ptr->val<minval && ptr->find==0)
		{   //假如ptr->val的值小于minval
			minval=ptr->val; //就把ptr->val设置最小值
			retptr=ptr;//并且把ptr纪录下来
		}
		ptr=ptr->next;
	}
	retptr->find=1;    //将retptr设为已找到的边
	return retptr;     //返回retptr
}
void mintree(mst head) //最小成本生成树子程序
{
	mst ptr,mceptr;
	int result=0;
	ptr=head;

	for(int i=0;i<=VERTS;i++)
		v[i]=0;

	while(ptr!=NULL)
	{
		mceptr=findmincost(head);
		v[mceptr->from]++;
		v[mceptr->to]++;
		if(v[mceptr->from]>1 && v[mceptr->to]>1)
		{
			v[mceptr->from]--;
			v[mceptr->to]--;
			result=1;
		}
		else
			result=0;
		if(result==0)
			cout<<"起始顶点 ["<<mceptr->from
            <<"]\t终止顶点 ["<<mceptr->to<<"]\t路径长度 ["
            <<mceptr->val<<"]"<<endl;
		ptr=ptr->next;
	}
}
