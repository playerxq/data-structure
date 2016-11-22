// uva-439-骑士移动.cpp : 定义控制台应用程序的入口点。
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
int mp[8][8];
int vis[8][8];
int num[8][8];
int front;
int rear ;
int queue[64];
int nx,ny;
int dir[8][2]={{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2}};
void bfs(int x ,int y)
{
	front = 0;
	rear = 0;
	int u = x*8+y;
	vis[x][y] = 1;
	num[x][y] = 0;
	queue[rear++] = u;
	while(front<rear)
	{
		u = queue[front++];
		x = u/8;
		y = u%8;
		for(int i = 0;i<8;i++)
		{
			nx = x+dir[i][0];
			ny = y+dir[i][1];
			if(nx>=0&&nx<8&&ny<8&&ny>=0&&vis[nx][ny]==0)
			{
				int v = nx*8+ny;
				queue[rear++] = v;
				vis[nx][ny] = 1;
				num[nx][ny] = num[x][y]+1;
			}
		}
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	char a[10];
	char b[10];
	while(scanf("%s%s",a,b)!=EOF)
	{
		memset(mp,0,sizeof(mp));
		memset(vis,0,sizeof(vis));
		memset(num,0,sizeof(num));
		memset(queue,0,sizeof(queue));
		
		bfs(a[1]-'1',a[0]-'a');
		printf ("To get from %s to %s takes %d knight moves.\n",  
            a, b, num[b[1]-'1'][b[0]-'a']);
	}
	return 0;
}

