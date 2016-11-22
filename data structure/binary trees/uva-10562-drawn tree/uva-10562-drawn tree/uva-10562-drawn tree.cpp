// uva-10562-drawn tree.cpp : 定义控制台应用程序的入口点。
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
char mp[220][220];

void dfs(int x,int y)//从第x行 y列开始  y应该是当前子树第一行‘-’的第一个
{
	int i;
	i = y;
	for(;mp[x][i] == '-';i++)//y为第一个  故全部覆盖下面的子节点
	{
		if (mp[x + 1][i] != ' ' && mp[x + 1][i] != '\0')
		{
			printf("%c(",mp[x+1][i]);
			if(mp[x + 2][i]=='|')
			{
				int j = i;
				while(j>0&&mp[x+3][j-1]=='-') j--;//找到第一个'-'
				dfs(x+3,j);
			}
			printf(")");
		}
	}
}

void solve()
{
	for (int i = 0; mp[1][i]; i++)  //最上面一行加‘-’使得可以3行一组的处理
        mp[0][i] = '-'; 
	printf("(");  
    dfs(0, 0);  
    printf(")\n");
}
int main()
{
	int T;
	scanf("%d",&T);
	getchar();
	int n;
	while(T--)
	{
		memset(mp,'\0',sizeof(mp));
		n = 1;
		while(gets(mp[n]))
		{
			if(mp[n][0]=='#')
			{
				n--;
				break;
			}
			n++;
		}
		if(!n)
			printf("()\n");//empty
		else
			solve();
	}
	return 0;
}

