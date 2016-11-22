// hdu-1298.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
struct node
{
	int count;
	node *childs[26];
	node()
	{
		count=0;
		for(int i=0;i<26;i++)
			childs[i]=NULL;
	}
};
node *root;
node *current,*newnode;
int p;
char s1[105],s2[105],findx[105],ans[105];
char phone[8][4]={{0,1,2},{3,4,5},{6,7,8},{9,10,11},{12,13,14},{15,16,17,18},{19,20,21},{22,23,24,25}};
int  num[8]={3,3,3,3,3,4,3,4};
void insert(char *str,int k) //�����ַ���������Ƶ��
{
	int i,m;
	current=root;
	for(i=0;i<strlen(str);i++)
	{
		m=str[i]-'a';
		if(current->childs[m]!=NULL)
		{
			current=current->childs[m];
			(current->count)+=k;
		}
		else
		{
			newnode=new node;
			(newnode->count)+=k;
			current->childs[m]=newnode;
			current=newnode;
		}
	}
}
void dfs(int cur,int len,node *nd)
{
    if(cur==len)
	{
		if(nd->count>p)   //��Ƶ�����ĵ���
		{
			p=nd->count;
            for(int i=0;i<len;i++)
				findx[i]=ans[i];
			findx[len]='\0';
		}
	    return;
	}
    int t=s2[cur]-'2';//��ǰ�ַ���Ӧ�ļ�
    for(int i=0;i<num[t];i++)//���ϵ��ַ�
	{
		int r=phone[t][i];//ÿ���ַ�
		if(nd->childs[r]==NULL)//�鿴�Ƿ��е����д��ַ��ڴ�λ�ó��ֹ�
			continue;
		ans[cur]='a'+r;//���ֹ�  �����ַ�
        dfs(cur+1,len,nd->childs[r]);
	}
	return;
}
int main()
{
	int i,n,m,t,k,cnt,len;
	scanf("%d",&t);
	for(k=1;k<=t;k++)
	{
		printf("Scenario #%d:\n",k);
		scanf("%d",&n);
		root=new node;
		while(n--)
		{
			scanf("%s %d",s1,&cnt);
			insert(s1,cnt);
		}
		scanf("%d",&m);
		while(m--)
		{
			scanf("%s",s2);
			len=strlen(s2);
			for(i=1;i<len;i++)
			{
				p=0;  //��¼�ַ����ֵ�Ƶ��
				dfs(0,i,root);
				if(p>0)
					printf("%s\n",findx);
				else
					printf("MANUALLY\n");
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}


