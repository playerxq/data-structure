// uva-532-3D maze.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
#define size 31
struct node
{int x;int y;int z; int time;} queue[size*size*size];
int f,l,r,c,top,tail,visit[size][size][size],move[6][3]={0,1,0,0,-1,0,0,0,1,0,0,-1,1,0,0,-1,0,0};//east west up down sourth north
char s[size][size][size];

int Bfs()  
{
	int i,px=queue[top].x,py=queue[top].y,pz=queue[top].z,X,Y,Z;  
	 if (f) return 0;  
	 if (s[px][py][pz]=='E') {f=1; return 0;}  
	 if (top>tail) return 0;  
	 for (i=0;i<6;i++)  
	 {
		 X=px+move[i][0];  
		  Y=py+move[i][1];  
		  Z=pz+move[i][2];  
		  if ((X>0)&&(X<=l)&&(Y>0)&&(Y<=r)&&(Z>0)&&(Z<=c)&&(s[X][Y][Z]!='#')&&(visit[X][Y][Z]==1))  
		  {
			  ++tail;  
			   queue[tail].x=X;  
			   queue[tail].y=Y;  
			   queue[tail].z=Z;  
			   queue[tail].time=queue[top].time+1;  
			   visit[X][Y][Z]=0;  
			}  
	 }  
	 ++top;  
	 Bfs();  
};
int main()
{
	int i,j,k;  
	 while (scanf("%d%d%d",&l,&r,&c),l+r+c)  
	 {  
		  for (i=1;i<=l;i++)  
		  {
			  getchar();  
			  for (j=1;j<=r;j++)  
			  {
				  for (k=1;k<=c;k++)  
				  {
					  scanf("%c",&s[i][j][k]);  
					  visit[i][j][k]=1;  
				      if (s[i][j][k]=='S')  
				      {
						  queue[1].x=i; queue[1].y=j;  
				          queue[1].z=k; queue[1].time=0;  
				          visit[i][j][k]=0;  
				      }  
				   }  
				  getchar();  
		      }  
	  }  
	  top=1; tail=1; f=0;  
	  Bfs();  
	  if (f) printf("Escaped in %d minute(s).\n",queue[top].time);  
		else printf("Trapped!\n");  
	 }  
	 return 0; 
}

