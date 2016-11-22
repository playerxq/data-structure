// hdu-1247.cpp : 定义控制台应用程序的入口点。
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
	Node* next[26];
	int flag;
};
Node* root;
char s[50002][100];
Node* get_new()
{
	Node* p = (Node*)malloc(sizeof(Node));
	for(int i = 0;i<26;i++)
	{
		p->next[i]=0;
	}
	p->flag = 0;
	return p;
}
void init()
{
	root = get_new();
}
void insert(char* s)
{
	Node* p = root;
	for(;*s!='\0';s++)
    {
        int d=*s-'a';
        if(p->next[d]==NULL)
        {
            p->next[d]=get_new();
            p=p->next[d];
        }
        else p=p->next[d];
    }
	p->flag=1;
}
int find1(char* s)
{
	Node* p = root;
	int n = strlen(s);
	for(;*s!='\0';)
	{
		if(p->next[*s-'a'])
		{
			if(p->next[*s-'a']->flag==1)
			{
				if(*(s+1)=='\0')
					return 1;
			}
			p = p->next[*s-'a'];
			s++;
		}
		else
			return 0;
	}
	return 0;
}
int find(char* s)
{
	Node* p = root;
	while(*s!='\0')
	{
		if(p->next[*s-'a']->flag==1)
		{
			if(find1(s+1))
				return 1;
		}
		p = p->next[*s-'a'];
		s++;
	}
	return 0;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	init();
	int i = 0;
	while(scanf("%s",s[i])!=EOF)
	{
		insert(s[i++]);
	}
	for(int j = 0;j<i;j++)
	{
		if(find(s[j]))
			printf("%s\n",s[j]);
	}
}

