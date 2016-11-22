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
    //�˳�������
    if(*s=='\0') return NULL;

    //�½�һ�����
    Node *root;
    root=new Node;
    root->flag=*s;
    for(int i=0;i<4;++i) root->child[i]=NULL;

    //��ľ���ӽ��
    if(*s=='p')
    {
        for(int i=0;i<4;++i)
        {
            ++s;
            root->child[i]=build();//����4���ַ����Ǻ���
        }
    }
    return root;//�����½��Ľ��
}
void dfs(Node *root1,Node *root2,int cur)//��ǰ�߶�Ϊcur ��0��ʼ  1024����2*cur
{
    //�˳�������
    if(root1==NULL&&root2==NULL) return;
    if(root1==NULL)//���1���գ�ֻ����2��
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
    if(root2==NULL)//ͬ��
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
    if(root1->flag=='f'||root2->flag=='f')//�����һ�������f�Ļ�����ô�����ڱ����ˣ�ֱ���˳�
    {
        ans+=1024>>(2*cur);
        return;
    }
    for(int i=0;i<4;++i) dfs(root1->child[i],root2->child[i],cur+1);//��������
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