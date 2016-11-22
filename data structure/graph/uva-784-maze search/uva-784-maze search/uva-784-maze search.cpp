// uva-784-maze search.cpp : 定义控制台应用程序的入口点。
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
char mp[40][100];
int used[40][100];
int row,column;
void dfs(int x,int y)//(x,y)为房屋中点  可由start进入
{
	if(used[x][y])
	{
		return;
	}
	used[x][y] = 1;
	if(mp[x-2][y]==' ')
	{
		mp[x-4][y] = '*';
		dfs(x-4,y);
	}
	if(mp[x+2][y]==' ')
	{
		mp[x+4][y] = '*';
		dfs(x+4,y);
	}
	if(mp[x][y-2]==' ')
	{
		mp[x][y-4] = '*';
		dfs(x,y-4);
	}
	if(mp[x][y+2]==' ')
	{
		mp[x][y+4] = '*';
		dfs(x,y+4);
	}
	return;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int ncase = 0;
	scanf("%d",&ncase);
	getchar();
	while(ncase--)
	{
		memset(mp,0,sizeof(mp));
		memset(used,0,sizeof(used));
		int i = 0;
		while(gets(mp[i]))
		{
			if(mp[i][0]=='_')
				break;
			else
			{
				int temp = strlen(mp[i]);
				if(temp>column) column = temp;
				i++;
			}
		}
		row = i;//mp[row]为'_____'
		for(i = 0;i<row;i++)
		{
			for(int j = 0;j<column;j++)
			{
				if(mp[i][j]=='*')
				{
					dfs(i,j);
					break;
				}
			}
		}
		for(i = 0;i<row;i++)//将*所在房间涂成#
		{
			for(int j = 0;j<column;j++)
			{
				if(mp[i][j]=='*')
				{
					for(int k = i-2;k<i+3;k++)
					{
						for(int h = j-2;h<j+3;h++)
							if(mp[k][h]==' '||mp[k][h]=='*')
							{
								mp[k][h] = '#';
							}
					}
				}
			}
		}
		for(int i = 0;i<row+1;i++)
			printf("%s\n",mp[i]);
	}
	return 0;
}

