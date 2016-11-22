// uva-712-s tree.cpp : 定义控制台应用程序的入口点。
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
int i_x;
int m[150];
int a[150];
int b[150];
int temp[150];
int ans[20000];
void sort_by_m(int n)
{
	for(int i = 0;i<n;i++)
	{
		temp[i] = b[m[i]-1];
	}
	for(int i = 0;i<n;i++)
	{
		b[i] = temp[i];
	}
	memset(temp,0,sizeof(temp));
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int n;
	int ncase = 0;
	char x;
	while(scanf("%d",&n))
	{
		if(n==0)
			break;
		ncase++;
		i_x =0;
		memset(m,0,sizeof(m));
		for(int i = 0;i<n;i++)
		{
			getchar();
			scanf("%c%d",&x,&m[i_x++]);
		}
		i_x = 0;
		for(int i = 0;i<pow(2,(double)n);i++)
		{
			scanf("%1d",&a[i_x++]);
		}
		int num = 0;
		scanf("%d",&num);
		memset(ans,0,sizeof(ans));
		for(int i = 0;i<num;i++)
		{
			i_x = 0;
			memset(b,0,sizeof(b));
			for(int j = 0;j<n;j++)
			{
				scanf("%1d",&b[i_x++]);
			}
			sort_by_m(n);
			int sum = 0;
			for(int k = 0;k<n;k++)
			{
				if(b[k])
					sum += pow(2,(double)(n-k-1));
			}
			ans[i] = a[sum];
		}
		printf("S-Tree #%d:\n",ncase);
		for (int i=0;i<num;i++)
			printf("%d",ans[i]);
		printf("\n\n");
	}
	return 0;
}

