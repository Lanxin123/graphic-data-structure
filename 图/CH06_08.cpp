/*
[示范]:Floyd算法(所有顶点两两之间的最短距离)
*/
#include <iostream>
#include <cstdlib>
#include <iomanip>
#define SIZE   7  
#define INFINITE  99999 //无穷大
#define NUMBER 6
using namespace std;
int Graph_Matrix[SIZE][SIZE];//图的数组
int distance[SIZE][SIZE];		//路径长度的数组
//建立图 
void BuildGraph_Matrix(int *Path_Cost)
{
   int Start_Point;	//边的起点
   int End_Point; 	//边的终点 
   int i, j;
   for ( i = 1; i < SIZE; i++ )
      for ( j = 1; j < SIZE; j++ )
         if (i==j)
            Graph_Matrix[i][j] = 0; //对角线设为0
         else
            Graph_Matrix[i][j] = INFINITE;  
   //存入图形的边
   i=0;
   while(i<SIZE)
   {
      Start_Point = Path_Cost[i*3]; 
      End_Point = Path_Cost[i*3+1]; 
      Graph_Matrix[Start_Point][End_Point]=Path_Cost[i*3+2];
      i++;
   }
}
//打印出图
void printGraph_Matrix()
{
   int i, j;
   for ( i = 1; i < SIZE; i++ )
   {
      cout<<"vex%d"<<i;
      for ( j = 1; j < SIZE; j++ )
         if ( Graph_Matrix[i][j] == INFINITE )
            cout<<setw(5)<<'x';
         else
            cout<<setw(5)<<Graph_Matrix[i][j];
      cout<<endl;
   }
}
//单点对全部顶点的最短距离 
void shortestPath(int vertex_total)
{       
   int i,j,k;
   extern int distance[SIZE][SIZE];		//声明为外部变量 
   //图的长度数组初始化
   for (i=1;i<=vertex_total;i++ )
      for (j=i;j<=vertex_total;j++ )
         {
            distance[i][j]=Graph_Matrix[i][j]; 
            distance[j][i]=Graph_Matrix[i][j];        
         }
   //利用Floyd算法找出所有顶点两两之间的最短距离
   for (k=1;k<=vertex_total;k++ ) 
      for (i=1;i<=vertex_total;i++ )
         for (j=1;j<=vertex_total;j++ )
            if (distance[i][k]+distance[k][j]<distance[i][j])
                distance[i][j] = distance[i][k] + distance[k][j];   
}
//主程序
int main(void) 
{
   extern int distance[SIZE][SIZE];		//声明为外部变量
   int Path_Cost[7][3] = { {1, 2, 10}, 
                      {2, 3, 20},
                      {2, 4, 25},
                      {3, 5, 18},
                      {4, 5, 22},
                      {4, 6, 95},
                      {5, 6, 77} }; 
   int i,j;
   BuildGraph_Matrix(&Path_Cost[0][0]);
   cout<<"=================================="<<endl;
   cout<<"此范例图形的邻接矩阵如下: "<<endl;
   cout<<"=================================="<<endl;
   cout<<"顶点 vex1 vex2 vex3 vex4 vex5 vex6"<<endl;
   printGraph_Matrix();  //显示图的邻接矩阵
   cout<<"=================================="<<endl;
   cout<<"所有顶点两两之间的最短距离: "<<endl;
   cout<<"=================================="<<endl;
   shortestPath(NUMBER); //计算所有顶点间的最短路径
   //求得两两顶点间的最短路径长度数组后，将其打印出来
   cout<<"顶点 vex1 vex2 vex3 vex4 vex5 vex6"<<endl;
      for ( i = 1; i <= NUMBER; i++ )
      {
         cout<<"vex"<<i;
         for ( j = 1; j <= NUMBER; j++ )
         {
            cout<<setw(5)<<distance[i][j];
         }
         cout<<endl;
      }
   cout<<endl;
   system("pause");
   return 0; 
}
