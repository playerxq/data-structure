// uva-572-油田.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
char mp[150][150];
int used[150][150];
int count_x;

void dfs(int x,int y)
{
	if(used[x][y]||mp[x][y]=='*')
		return;
	used[x][y] = 1;
	dfs(x-1,y-1);
	dfs(x-1,y);
	dfs(x-1,y+1);
	dfs(x,y-1);
	dfs(x,y+1);
	dfs(x+1,y-1);
	dfs(x+1,y);
	dfs(x+1,y+1);
}

int main()
{
	int m,n;
	while(scanf("%d%d",&m,&n))
	{
		if(m==0) break;
		getchar();
		memset(mp,0,sizeof(mp));
		memset(used,0,sizeof(used));
		for(int i = 1;i<m+1;i++)
			gets(mp[i]+1);
		count_x = 0;
		for(int i = 0;i<m+2;i++)
		{
			mp[i][0] = '*';
			mp[i][n+1] = '*';
		}
		for(int i = 0;i<n+2;i++)
		{
			mp[0][i] = '*';
			mp[m+1][i] = '*';
		}
		for(int i = 0;i<m+1;i++)
		{
			for(int j = 0;j<n+1;j++)
			{
				if(!used[i][j]&&mp[i][j]=='@')
				{
					count_x++;
					dfs(i,j);
				}
			}
		}
		printf("%d\n",count_x);
	}
	return 0;
}

