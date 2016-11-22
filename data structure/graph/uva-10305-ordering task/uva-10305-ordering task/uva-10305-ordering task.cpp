// uva-10305-ordering task.cpp : 定义控制台应用程序的入口点。
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
int map[110][110];
int c[110];
int used[110];
int topo[110];
int top;
int p_n;

int dfs(int start)
{
	c[start] = -1;//正在访问
	for(int i = 1;i<=p_n;i++)
	{
		if(map[start][i])
		{
			if(c[i]==-1)
				return 0;//回路
			else if(c[i]==0&&!dfs(i)) return 0;//排序失败
		}
	}
	c[start] = 1;
	topo[--top] = start;
	return 1;
}

bool topsort()
{
	top = p_n;
	for(int i = 1;i<=p_n;i++)
	{
		if(!c[i])
			if(!dfs(i))
				return false;
	}
	return true;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m;
	while(scanf("%d%d",&n,&m))
	{
		if(n==0&&m==0)
			break;
		memset(map,0,sizeof(map));
		memset(c,0,sizeof(c));
		memset(topo,0,sizeof(topo));
		memset(used,0,sizeof(used));
		top = 0;
		p_n = 0;
		for(int i = 0;i<n;i++)
			used[i+1] = 1;
		p_n = n;
		int s,e;
		for(int i = 0;i<m;i++)
		{
			scanf("%d %d",&s,&e);
			map[s][e] = 1;
		}
		topsort();
		for(int i = 0;i<p_n;i++)
		{
			printf("%d",topo[i]);
			if(i==p_n-1)
				printf("\n");
			else
				printf(" ");
		}
	}
	return 0;
}
