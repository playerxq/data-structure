// uva-10562-drawn tree.cpp : �������̨Ӧ�ó������ڵ㡣
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

void dfs(int x,int y)//�ӵ�x�� y�п�ʼ  yӦ���ǵ�ǰ������һ�С�-���ĵ�һ��
{
	int i;
	i = y;
	for(;mp[x][i] == '-';i++)//yΪ��һ��  ��ȫ������������ӽڵ�
	{
		if (mp[x + 1][i] != ' ' && mp[x + 1][i] != '\0')
		{
			printf("%c(",mp[x+1][i]);
			if(mp[x + 2][i]=='|')
			{
				int j = i;
				while(j>0&&mp[x+3][j-1]=='-') j--;//�ҵ���һ��'-'
				dfs(x+3,j);
			}
			printf(")");
		}
	}
}

void solve()
{
	for (int i = 0; mp[1][i]; i++)  //������һ�мӡ�-��ʹ�ÿ���3��һ��Ĵ���
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

