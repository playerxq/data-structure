// hdu-1116-欧拉.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <math.h>
#include<iomanip>
#include <ctype.h>
#include <vector>
#include <algorithm>
using namespace std;
int num;
int flag;
int p_n;//当前的点数
int in[30],out[30],p[30],vis[30],dep[30];

int find(int x)
{
	return p[x]==x?p[x]:p[x]=find(p[x]);
}


void union_set(int a, int b)
{
	a = find(a);
	b = find(b);
	if(a==b)
		return;
	if(dep[a]>dep[b])
		p[b]=a;
	else
	{
		if(dep[a]==dep[b])
			dep[b]++;
		p[a]=b;
	}
	return;
}
void init()
{
	for(int i = 0;i<30;i++)
	{
		p[i]=i;
		dep[i]=0;
		in[i]=out[i]=vis[i]=0;
	}
}
string str;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	int i,a,b,count,k,f[30]; 
	scanf("%d",&T);
	int ncase = 0;
	while(T--)
	{
		scanf("%d",&num);
		init();
		for(i = 1;i<=num;i++)
		{
			cin>>str;
			a = str[0]-'a';
			b = str[str.size()-1]-'a';
			in[a]++;
			out[b]++;
			vis[a]=1;vis[b]=1;
			union_set(a,b);//一个单词  属于一个集合
		}
		/*判断有向图是否连通*/ 
        for(i=0,count=0;i<30;i++) 
        { 
            if((vis[i])&&p[i]==i) 
                count++; 
        } 
        flag=0;//通 
		if(count!=1) 
        { 
            cout<<"The door cannot be opened."<<endl; 
            continue; 
        }
		for(i=0,k=0;i<30;i++) 
        { 
            if(in[i]!=out[i])//找出入度与出度不相同的点 
                f[k++]=i; 
        }
		if(k==0||k==2)
        { 
            if(k==0) 
            {         
                flag=0; 
            } 
            else 
            { 
                if( (out[f[0]]-in[f[0]]==1 && in[f[1]]-out[f[1]]==1)||( out[f[1]]-in[f[1]]==1 && in[f[0]]-out[f[0]]==1 ) ) 
                { 
                    flag=0; 
                } 
                else 
                    flag=1; 
            } 
        }
		else 
        { 
            flag=1; 
        } 
        if(flag) 
            cout<<"The door cannot be opened."<<endl; 
        else 
            cout<<"Ordering is possible."<<endl; 
    }
	return 0;
}

