// hdu-2586.cpp : �������̨Ӧ�ó������ڵ㡣
//�Ƚ�һ������Ȼ�����ÿһ��i�������ľ���dis[i],Ȼ��ÿ��ѯ��a��b֮��ľ���=dis[a]+dis[b]-2*dis[LCA(a,b)];
//LCA(a,b)����a��b������������ȡ���
/*
����������������Ϊ�����ϣ��õ�����Tarjan��˼�룬
�Ӹ���㿪ʼ�γ�һ�����������ǳ��õĴ����ɾ����ڻ��ݵ����u��ʱ��u�������Ѿ���������ʱ��Ű�u������ϲ������У�
����u��������u�������еĽ�������������Ⱦ���u�ˣ�u�ͻ�δ����������u���ֵܽ�㼰�����е�����������Ⱦ���u�ĸ��׽�㡣
�Դ����ơ������������ڶ�����ȱ�����ʱ��ͺ���Ȼ�Ľ����еĽ��ֳ����ɵļ��ϣ����������е�������ͬ���ϵ�����һ�Զ���Ĺ������ȶ�����ͬ�ģ�Ҳ����˵���������ϵ������������ֻ��һ����
����ÿ�����϶��Կ����ò��鼯���Ż���ʱ�临�ӶȾʹ�󽵵��ˣ�ΪO(n + q)��nΪ�ܽ������qΪѯ�ʽ�������
*/
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
#define NN 40002
#define MM 202
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

int idx1,idx2,N,M;
int res[MM][3];//// ��¼��i����ѯ�����res[i][0]: u   res[i][1]: v  res[i][2]: lca(u, v)
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
			res[pt->d][2]=find(pt->v);//pt->d=i����ѯ��� pt->v��u�Ĺ������Ⱦ���p[pt->v] ʹ�ò��鼯�Ż�ÿ����ͬ�����ڵ�ļ���
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

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int T, i, u, v, d;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &N, &M);

        idx1 = 0;
        memset(Link1, 0, sizeof(Link1));
        for (i = 1; i < N; i++){
            scanf("%d%d%d", &u, &v, &d);
            add(u, v, d, edge1, Link1, idx1);
        }

        idx2 = 0;
        memset(Link2, 0, sizeof(Link2));
        for (i = 1; i <= M; i++){
            scanf("%d%d", &u, &v);
            add(u, v, i, edge2, Link2, idx2);//����ѯ�����ӱ�  ����d=i����ѯ���
            res[i][0] = u;
            res[i][1] = v;
        }

        memset(vis, 0, sizeof(vis));
        dis[1] = 0;
        Tarjan(1);

        for (i = 1; i <= M; i++){
            printf("%d\n", dis[res[i][0]] + dis[res[i][1]] - 2 * dis[res[i][2]]);
        }
    }
    return 0;
}
