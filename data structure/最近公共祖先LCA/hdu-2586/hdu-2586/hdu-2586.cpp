// hdu-2586.cpp : 定义控制台应用程序的入口点。
//先建一棵树，然后求出每一点i到树根的距离dis[i],然后每次询问a，b之间的距离=dis[a]+dis[b]-2*dis[LCA(a,b)];
//LCA(a,b)即是a，b的最近公共祖先。。
/*
在求解最近公共祖先为问题上，用到的是Tarjan的思想，
从根结点开始形成一棵深搜树，非常好的处理技巧就是在回溯到结点u的时候，u的子树已经遍历，这时候才把u结点放入合并集合中，
这样u结点和所有u的子树中的结点的最近公共祖先就是u了，u和还未遍历的所有u的兄弟结点及子树中的最近公共祖先就是u的父亲结点。
以此类推。。这样我们在对树深度遍历的时候就很自然的将树中的结点分成若干的集合，两个集合中的所属不同集合的任意一对顶点的公共祖先都是相同的，也就是说这两个集合的最近公共最先只有一个。
对于每个集合而言可以用并查集来优化，时间复杂度就大大降低了，为O(n + q)，n为总结点数，q为询问结点对数。
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
//原图
NODE* Link1[NN];
NODE edge1[NN*2];
//询问
NODE* Link2[NN];
NODE edge2[NN*2];

int idx1,idx2,N,M;
int res[MM][3];//// 记录第i个问询结果，res[i][0]: u   res[i][1]: v  res[i][2]: lca(u, v)
int p[NN],vis[NN],dis[NN];
int find(int x)  
{  
    return p[x]==x?x:p[x]=find(p[x]);  
}
void add(int u, int v , int d, NODE edge[], NODE* Link[], int& idx)
{
	//将边串接到链表Link[u]上
	edge[idx].v=v;
	edge[idx].d=d;
	edge[idx].nxt=Link[u];//插入
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
	for(NODE* pt=Link2[u];pt;pt = pt->nxt)//查看u出发已经访问过的问询节点
	{
		if(vis[pt->v])
			res[pt->d][2]=find(pt->v);//pt->d=i即问询序号 pt->v与u的公共祖先就是p[pt->v] 使用并查集优化每组相同公共节点的集合
	}
	//对原图设置公共节点
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
            add(u, v, i, edge2, Link2, idx2);//对问询的链接表  距离d=i即问询序号
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
