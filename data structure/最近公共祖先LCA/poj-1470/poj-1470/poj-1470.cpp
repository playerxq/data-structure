// poj-1470.cpp : �������̨Ӧ�ó������ڵ㡣
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
#define NN 902
typedef struct node
{
	int v,d;
	struct node* nxt;
} NODE;
NODE* Link1[NN];
NODE edge1[NN*2];
NODE* Link2[NN];
NODE edge2[NN*1000];
int idx1, idx2, N, M;
int p[NN];
int vis[NN];
int cnt[NN];
int find(int x)
{
	return p[x]==x?x:p[x]=find(p[x]);
}
void Init(NODE *Link[], int &idx){
    memset(Link, 0, sizeof(Link[0]) * (N + 1));
    idx = 0;
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
void Tarjan(int u){
    vis[u] = 1;
    p[u] = u;
    for (NODE *pt = Link2[u]; pt; pt = pt->nxt){
        if(vis[pt->v]){
            cnt[find(pt->v)]++;
        }
    }

    for (NODE *pt = Link1[u]; pt; pt = pt->nxt){
        if(!vis[pt->v]){
            Tarjan(pt->v);
            p[pt->v] = u;
        }
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int i, u, v, n, root;
    int flag[NN];
    while(scanf("%d", &N) != EOF){

        Init(Link1, idx1);
        memset(flag, 0, sizeof(flag));
        for (i = 1; i <= N; i++){ 
            scanf("%d", &u);
            while(getchar() != '(');
            scanf("%d", &n);//n���ӽڵ�
            while(getchar() != ')');
            while(n--){
                scanf("%d", &v);
                flag[v] = 1;
                add(u, v, 0,edge1, Link1, idx1);//����d�ڴ�������
            }
        }
        scanf("%d", &M);
        Init(Link2, idx2);
        for (i = 1; i <= M; i++){
            while(getchar() != '(');
            scanf("%d%d", &u, &v);
            while(getchar() != ')');
            add(u, v, 0,edge2, Link2, idx2);
        }

        memset(vis, 0, sizeof(vis));
        memset(cnt, 0, sizeof(cnt));

        for (i = 1; i <= N; i++){// ��һ����㲻һ���Ǹ����
            if(flag[i] == 0) break;
        }
        root = i; 
        Tarjan(root);

        for (i = 1; i <= N; i++){
            if(cnt[i]){
                printf("%d:%d\n", i, cnt[i]);
            }
        }
    }
    return 0;
}

