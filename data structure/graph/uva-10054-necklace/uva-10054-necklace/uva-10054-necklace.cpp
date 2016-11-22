// uva-10054-necklace.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include<iomanip>
#include <ctype.h>
#include <vector>
#include <algorithm>
using namespace std;
int num;
int flag;
int p_n;//当前的点数
int used[60];
int visit[60];
int vis[60][60];
int map[60][60];
int degree[60];

typedef struct node
{
	int u;
	int v;
	node(int x,int y):u(x),v(y){}
} node;
vector<node> ve;

//判断是否连通
int len;
int dfs(int start)
{
    int i;  
    visit[start] = true;  
	len++;
	if (len == p_n)  
        return true;  
    for (i = 0; i < 60; i++)  
    {  
        if ((map[start][i]||map[i][start]) && !visit[i])  
        {  
            if (dfs(i))  
                return true;  
        }  
    }
    return false; 
}
int judge_degree()
{
	for(int i = 0;i<60;i++)
	{
		if(used[i]&&(degree[i]==0||(degree[i]%2!=0)))
			return 0;
	}
	return 1;
}

void euler(int start)
{
	for(int i = 0;i<60;i++)
	{
		if(map[start][i])
		{
			map[start][i]--;
			map[i][start]--;
			euler(i);
			node no(start,i);
			ve.push_back(no);
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	int ncase = 0;
	while(T--)
	{
		scanf("%d",&num);
		int s,e;
		memset(map,0,sizeof(map));
		memset(degree,0,sizeof(degree));
		memset(used,0,sizeof(used));
		memset(visit,0,sizeof(visit));
		memset(vis,0,sizeof(vis));
		for(int i = 0;i<num;i++)
		{
			scanf("%d %d",&s,&e);
			map[s][e] += 1;
			map[e][s] += 1;
			degree[s]++;
			degree[e]++;
			used[s] = used[e] = 1;
		}
		p_n = 0;
		for(int i = 0;i<60;i++)
			if(used[i])
				p_n++;
		flag = 0;
		int pos;
		for(int i = 0;i<60;i++)
		{
			if (degree[i] != 0)  
			{
				pos = i;
                break;
			}
		}
		len = 0;
		flag = dfs(pos);
		flag&=judge_degree();//判断是否存在欧拉回路
		printf("Case #%d\n",++ncase);
		if(!flag)
			printf("some beads may be lost\n\n");
		else
		{
			//打印欧拉回路
			euler(pos);
			while(ve.empty()!=true)
			{
				node no = ve.back();
				printf("%d %d\n",no.u,no.v);
				ve.pop_back();
			}
			printf("\n");
		}
	}
	return 0;
}

