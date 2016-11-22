// poj-1330.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
#define NN 10002
typedef struct node
{
	int v,d;
	struct node* nxt;
} NODE;
//ԭͼ
NODE* Link1[NN];
NODE edge1[NN*2];
//ѯ��
NODE* Link2[NN];
NODE edge2[NN*2];

int idx1,idx2,N,M,res;
int p[NN],vis[NN],dis[NN];
int find(int x)  
{  
    return p[x]==x?x:p[x]=find(p[x]);  
}
void add(int u, int v , int d, NODE edge[], NODE* Link[], int& idx)
{
	//���ߴ��ӵ�����Link[u]��
	edge[idx].v=v;
	edge[idx].d=d;
	edge[idx].nxt=Link[u];//����
	Link[u]=&(edge[idx++]);

	edge[idx].v=u;
	edge[idx].d=d;
	edge[idx].nxt=Link[v];
	Link[v]=&(edge[idx++]);
}

void Tarjan(int u)
{
	vis[u]=1;
	p[u]=u;
	for(NODE* pt=Link2[u];pt;pt = pt->nxt)//�鿴u�����Ѿ����ʹ�����ѯ�ڵ�
	{
		if(vis[pt->v])
			res=find(pt->v);//pt->d=i����ѯ��� pt->v��u�Ĺ������Ⱦ���p[pt->v] ʹ�ò��鼯�Ż�ÿ����ͬ�����ڵ�ļ���
	}
	//��ԭͼ���ù����ڵ�
	for(NODE* pt = Link1[u];pt;pt=pt->nxt)
	{
		if(!vis[pt->v])
		{
			dis[pt->v]=dis[u]+pt->d;
			Tarjan(pt->v);
			p[pt->v]=u;
		}
	}
}
int flag[NN];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int T,u,v,root;
	scanf("%d",&T);
	
	while(T--)
	{
		memset(flag,0,sizeof(flag));
		scanf("%d",&N);
		idx1 = 0;
		memset(Link1,0,sizeof(Link1));
		memset(edge1,0,sizeof(edge1));
		for(int i = 0;i<N-1;i++)
		{
			scanf("%d%d",&u,&v);
			add(u,v,0,edge1,Link1,idx1);
			flag[v]=1;//v�и��ڵ�
		}
		idx2 = 0;
		memset(Link2,0,sizeof(Link2));
		memset(edge2,0,sizeof(edge2));
		scanf("%d%d",&u,&v);
		add(u,v,0,edge2,Link2,idx2);
		for(int i = 1;i<=N;i++)
		{
			if(flag[i]==0)
			{
				root = i;
				break;
			}
		}
		memset(vis, 0, sizeof(vis));
		Tarjan(root);
		printf("%d\n",res);
	}
}

