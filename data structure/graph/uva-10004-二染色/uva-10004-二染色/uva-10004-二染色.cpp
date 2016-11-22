// uva-10004-二染色.cpp : 定义控制台应用程序的入口点。
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
int n,l;
int flag;
int map[210][210];
int color[210];
int visit[210];
int queue[210*210];
int front;
int rear;
void bfs()
{
	queue[rear++] = 0;
	color[0] = 0;
	visit[0] = 1;
	while(front<rear)
	{
		int p = queue[front++];
		for(int i = 0;i<n;i++)
		{
			if(map[p][i]&&visit[i]==0)
			{
				color[i] = 1-color[p];
				visit[i] = 1;
				queue[rear++] = i;
			}
			if(map[p][i]&&visit[i]&&color[i]==color[p])
			{
				flag = 0;
				return;
			}
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	while(scanf("%d",&n))
	{
		if(n==0) break;
		scanf("%d",&l);
		int p1,p2;
		memset(map,0,sizeof(map));
		memset(queue,0,sizeof(queue));
		memset(color,0,sizeof(color));
		memset(visit,0,sizeof(visit));
		for(int i = 0;i<l;i++)
		{
			scanf("%d %d",&p1,&p2);
			map[p1][p2] = 1;
			map[p2][p1] = 1;
		}
		flag = 1;
		front = 0;
		rear = 0;
		bfs();
		if(flag)
			printf("BICOLORABLE.\n");
		else
			printf("NOT BICOLORABLE.\n");
	}

	return 0;
}

