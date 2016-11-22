// uva-10557-XYZZY.cpp : �������̨Ӧ�ó������ڵ㡣
//��Դ·��ʹ��·���ʹ���0   ���ö��в������ȥ���׶��ڽӵ��ɳ�

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
#define maxn 500000
int queue[100];
int visit[101],low[101],energy[101],map[101][101]; 
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	while(scanf("%d",&n))
	{
		if(n==-1) break;
		for(int i = 1;i<=n;i++)
		{
			for(int j = 1;j<=n;j++)
			{
				map[i][j] = 0;
			}
		}
		int m;
		int x;
		for(int i = 1;i<=n;i++)
		{
			scanf("%d%d",&energy[i],&m);
			for(int j = 1;j<=m;j++)
			{
				scanf("%d",&x);
				map[i][x] = 1;
			}
		}
		for(int i = 1;i<=n;i++)
		{
			visit[i] = 1;
			low[i] = 0;
		}
		queue[0] = 1;
		visit[1] = 0;
		low[1] = 100;
		int top = 0;
		int tail = 1;
		int f = 0;
		int mx = 0;//��Ӵ���
		while(top!=tail)
		{
			for(int i = 1;i<=n;i++)
			{
				if(map[queue[top]][i]==1&&low[queue[top]]+energy[i]>low[i])
				{
					low[i] = low[queue[top]]+energy[i];
					if(visit[i]==1)
					{
						queue[tail] = i;
						tail = (tail+1)%100;
						visit[i] = 0;
						++mx;
					}
				}
			}
			visit[queue[top]] = 1;
			top = (top+1)%100;//���׳���  ͬʱ���Ϊ�������·��ʵ�
			if(low[n]>0){f = 1;break;}
			if(mx>maxn) {f = 0;break;};
		}
		if (f==1) printf("winnable\n");  
		else printf("hopeless\n"); 
	}
	return 0;
}

