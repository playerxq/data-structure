// hdu-1075.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string.h>
using namespace std;
typedef struct tree
{
    int num;
    int flag;
    tree *next[26];
}tree;
tree *root;
char s[1000000][15];
void creat(char str[],int tmp)
{
    int len=strlen(str);
    tree *p=root,*q;
    for(int i=0;i<len;i++)
    {
        int x=str[i]-'a';
        if(!p->next[x])
        {
            q=(tree *)malloc(sizeof(tree));
            q->num=tmp;
            q->flag=0;
            for(int j=0;j<26;j++)
                q->next[j]=NULL;
            p->next[x]=q;
            p=q;
        }
        else if(p->next[x]->flag==0)
        {
            p->next[x]->num=tmp;
            p=p->next[x];
        }
    }
    p->flag=1;                                 //标记单词末尾
}
int find(char str[])
{
    int len=strlen(str);
    tree *p=root;
    for(int i=0;i<len;i++)
    {
        int x=str[i]-'a';
        if(p->next[x])
            p=p->next[x];
        else
            return 0;
    }
    if(p->flag)                                   //如果是单词末尾，则返回对应值，否则返回0
        return p->num;
    else
        return 0;
}
void del(tree *root)
{
    for(int i=0;i<26;i++)
        if(root->next[i])
            del(root->next[i]);
    free(root);
}
int main()
{
    root=(tree *)malloc(sizeof(tree));
    for(int i=0;i<26;i++)
        root->next[i]=NULL;
    root->flag=0;
    root->num=0;
    char t[4000],f[20],b[4000];
    int j=1;
    scanf("%s",s[j]);
    while(1)
    {
        scanf("%s",s[j]);
        if(s[j][0]=='E')
            break;
        j++;
        scanf("%s",s[j]);
        creat(s[j],j);
        j++;
    }
    getchar();
    gets(b);
    while(1)
    {
        gets(t);
        if(t[0]=='E')
            break;
        int len=strlen(t);
        j=0;
        for(int i=0;i<len;i++)
        {
            if(t[i]>=97&&t[i]<=122)
            {
                f[j++]=t[i];
            }
            else
            {
                f[j]='\0';
                if(find(f))
                {
                    int num=find(f);
                    printf("%s",s[num-1]);
                }
                else
                {
                    printf("%s",f);
                }
                printf("%c",t[i]);
                memset(f,0,sizeof(f));                         //清空数组
                j=0;
            }
        }
        printf("\n");
    }
    del(root);
    return 0;
}

