// hdu-1671.cpp : 定义控制台应用程序的入口点。
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
struct Node 
{ 
     int next[10]; 
	 int cnt;
     void init(){memset(next,-1,sizeof(next));cnt = 0;} 
}node[100001]; 

int p; 

inline void preprocess(){node[p=0].init();} 

inline void insert(char s[]) 
{ 
    int index=0; //0代表根
	++node[index].cnt; 
	int len = strlen(s);
    for(int i=0;i<len;i++) 
    { 
       int x=s[i]-'0'; 
       if(node[index].next[x]==-1) 
       { 
          node[++p].init(); 
          node[index].next[x]=p; 
       } 
       index=node[index].next[x];
	   node[index].cnt++;
    } 
}
inline int find(char s[]) 
{ 
    int index=0; //0代表根
	int len = strlen(s);
    for(int i=0;i<len;i++) 
    { 
       int x=s[i]-'0';
       index=node[index].next[x];
	   if(i==len-1)
	   {
		   if(node[index].cnt==1)
			   return 1;
		   else
			   return 0;
	   }
    } 
	return 0;
}
int n;
char s[10001][11];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		preprocess();
		scanf("%d",&n);
		int i = 0;
		for(;i<n;i++)
		{
			scanf("%s",s[i]);
			insert(s[i]);
		}
		for(i=0;i<n;i++)
		{
			if(!find(s[i]))
				break;
		}
		if(i==n)
			printf("YES\n");
		else
			printf("NO\n");
	}
}

