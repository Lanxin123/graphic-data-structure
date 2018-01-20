/*
[示范]:Dijkstra算法(单点对全部顶点的最短路径)
*/
#include <iostream>
#include <cstdlib>
#include <iomanip>
#define SIZE   7  
#define NUMBER 6
#define INFINITE  99999		//无穷大
using namespace std;
int Graph_Matrix[SIZE][SIZE];		//存放图的数组
int distance[SIZE];				//路径的长度
//建立图 
void BuildGraph_Matrix(int *Path_Cost)
{
   int Start_Point;		//边的起点 
   int End_Point;		//边的终点
   int i, j;
   for ( i = 1; i < SIZE; i++ )
      for ( j = 1; j < SIZE; j++ )
         if ( i == j )
            Graph_Matrix[i][j] = 0;	//对角线设为0
         else
            Graph_Matrix[i][j] = INFINITE;  
   //存入图的边 
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
   cout<<"vex"<<i;
      for ( j = 1; j < SIZE; j++ )
         if ( Graph_Matrix[i][j] == INFINITE )
            cout<<setw(5)<<'x';
         else
            cout<<setw(5)<<Graph_Matrix[i][j];
      cout<<endl;
   }
}
//单点对全部顶点的最短距离 
void shortestPath(int vertex1, int vertex_total)
{       
   extern int distance[SIZE];		//声明为外部变量 
   int shortest_vertex = 1; 		//记录最短距离的顶点
   int shortest_distance;   		//记录最短距离
   int goal[SIZE]; 				//用来记录该顶点是否被选取
   int i,j;
   for ( i = 1; i <= vertex_total; i++ )
   { 
      goal[i] = 0;    
      distance[i] = Graph_Matrix[vertex1][i]; 
   }
   goal[vertex1] = 1;  
   distance[vertex1] = 0;  
   cout<<endl;   
   for (i=1; i<=vertex_total-1; i++ ) 
   {      
      shortest_distance = INFINITE;      
      //找出最短距离的顶点
      for (j=1;j<=vertex_total;j++ )
         if (goal[j]==0&&shortest_distance>distance[j])
         {
            shortest_distance=distance[j];                                              
            shortest_vertex=j;              
         }
      goal[shortest_vertex] = 1;   
      //计算开始顶点到各顶点的最短距离
      for (j=1;j<=vertex_total;j++ )
      {
         if ( goal[j] == 0 && 
         distance[shortest_vertex]+Graph_Matrix[shortest_vertex][j]
         <distance[j])
         {
           distance[j]=distance[shortest_vertex]
           +Graph_Matrix[shortest_vertex][j];
         }       
      }
   }
}
//主程序
int main(void) 
{
   extern int distance[SIZE];		//声明为外部变量
   int Path_Cost[7][3] = { {1, 2, 10}, 
                      {2, 3, 20},
                      {2, 4, 25},
                      {3, 5, 18},
                      {4, 5, 22},
                      {4, 6, 95},
                      {5, 6, 77} }; 
   int j;
   BuildGraph_Matrix(&Path_Cost[0][0]);
   cout<<"=================================="<<endl;
   cout<<"此范例图的邻接矩阵如下: "<<endl;
   cout<<"=================================="<<endl;
   cout<<"顶点 vex1 vex2 vex3 vex4 vex5 vex6"<<endl;
   printGraph_Matrix();  //显示图
   shortestPath(1,NUMBER); //查找最短路径
   cout<<"=================================="<<endl;
   cout<<"顶点1到各顶点最短距离的最终结果"<<endl;
   cout<<"=================================="<<endl;
   for (j=1;j<SIZE;j++) 
      cout<<"顶点 1到顶点"<<setw(2)<<j<<"的最短距离="
      <<setw(3)<<distance[j]<<endl;
   cout<<endl;
   system("pause");
   return 0; 
}
