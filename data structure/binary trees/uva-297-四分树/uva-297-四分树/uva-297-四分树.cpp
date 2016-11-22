#include "stdafx.h"
#include<stdio.h>
#include<string.h>
#include<iostream>
#define MAXN 100000
using namespace std;
char s1[MAXN],s2[MAXN];
char *s;
typedef struct node
{
    node *child[4];
    char flag;
} Node;
int ans;
Node* build()
{
    //退出的条件
    if(*s=='\0') return NULL;

    //新建一个结点
    Node *root;
    root=new Node;
    root->flag=*s;
    for(int i=0;i<4;++i) root->child[i]=NULL;

    //有木有子结点
    if(*s=='p')
    {
        for(int i=0;i<4;++i)
        {
            ++s;
            root->child[i]=build();//下面4个字符都是孩子
        }
    }
    return root;//返回新建的结点
}
void dfs(Node *root1,Node *root2,int cur)//当前高度为cur 从0开始  1024右移2*cur
{
    //退出的条件
    if(root1==NULL&&root2==NULL) return;
    if(root1==NULL)//如果1树空，只遍历2树
    {
        if(root2->flag=='f')
        {
            ans+=1024>>(2*cur);
            return;
        }
        if(root2->flag=='p')
           for(int i=0;i<4;++i) dfs(root1,root2->child[i],cur+1);
        return;
    }
    if(root2==NULL)//同上
    {
        if(root1->flag=='f')
        {
            ans+=1024>>(2*cur);
            return;
        }
        if(root1->flag=='p')
          for(int i=0;i<4;++i) dfs(root1->child[i],root2,cur+1);
        return;
    }
    if(root1->flag=='f'||root2->flag=='f')//如果有一个结点是f的话，那么不用在遍历了，直接退出
    {
        ans+=1024>>(2*cur);
        return;
    }
    for(int i=0;i<4;++i) dfs(root1->child[i],root2->child[i],cur+1);//继续遍历
    return;
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--){
       scanf("%s",s1);
       scanf("%s",s2);
       s=s1;
       Node *root1=build();
       s=s2;
       Node *root2=build();
       ans=0;
       dfs(root1,root2,0);
       printf("There are %d black pixels.\n",ans);
    }
       return 0;
}