// hdu-1269.cpp : 定义控制台应用程序的入口点。
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
const int maxn = 10010;
vector<int> g[maxn];
int n;
int Bcnt; /// 强连通分量的个数；  
int Top; /// 栈顶；  
int Index; /// 时间戳；  
int low[maxn], dfn[maxn];  
int belong[maxn], stack[maxn];  
bool instack[maxn];  
void Tarjan(int u)
{
	stack[Top++]=u;
	instack[u]=1;
	dfn[u]=low[u]=++Index;
	for(int i = 0;i<g[u].size();i++)
	{
		int v = g[u][i];
		if(!dfn[v])
		{
			Tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(instack[v])
		{
			low[u]=min(dfn[v],low[u]);
		}
	}
	if(low[u]==dfn[u])
	{
		++Bcnt;
		int v;
		do
		{
			v = stack[--Top];
			instack[v]=0;
			belong[v]=Bcnt;
		}while(u!=v);
	}
}

void Init_tarjan(){  
    Bcnt= Top= Index= 0;  
    for(int i=1; i<=n; ++i) low[i]= dfn[i]= 0;  
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int m;  
    while( scanf("%d%d",&n,&m)!=EOF){
		if(n==0&&m==0)
			break;
        for(int i=1; i<=n; ++i) g[i].clear();  
        while(m--){  
            int x, y;  
            scanf("%d%d", &x, &y);  
            g[x].push_back(y);  
        }  
        Init_tarjan();  
        for(int i=1; i<=n; ++i){  
            if( !dfn[i] )  
                Tarjan(i);  
        }
        puts( Bcnt==1 ? "Yes" : "No" );  
    }
	return 0;
}

