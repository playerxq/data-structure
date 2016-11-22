// uva-548-tree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include<iomanip>
#include <ctype.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 10000+10;
int inorder[maxn];
int postorder[maxn];

typedef struct Node{ 
    int data; 
    struct Node *left; 
    struct Node *right; 
} Node; 

vector<int>result; 
vector<Node*>pResult; 
Node node[maxn];
int nodeIndex = 0; 

 inline Node* NewNode(){ 
    node[nodeIndex].left = NULL; 
    node[nodeIndex].right = NULL; 
    return &node[nodeIndex++]; 
}



Node * InPostCreateTree(int *mid,int *post,int len){ 
    if(len == 0) 
        return NULL; 
    int i=len-1; 
    while(post[len-1] != mid[i]) 
        --i; 
    Node *h=NewNode(); 
    h->data=post[len-1]; 
    h->left=InPostCreateTree(mid,post,i); 
    h->right=InPostCreateTree(mid+i+1,post+i,len-i-1); 
    return h; 
}

void dfs(Node *root, int n){ 
    if(!root->left && !root->right){ //到达叶子
        result.push_back(n+root->data); 
        pResult.push_back(root); 
        return ; 
    } 
    if(root->left) dfs(root->left, n+root->data); 
    if(root->right) dfs(root->right, n+root->data); 
} 


int main()
{
	while(scanf("%d",&inorder[0])!=EOF)
	{
		int i = 1;
		int nIndex;
		while(getchar()!='\n')
		{
			scanf("%d",&inorder[i++]);
		}
		nIndex = i;
		for(i=0; i<nIndex; ++i)  
			scanf("%d", &postorder[i]); 
		nodeIndex = 0; 
		Node *root = InPostCreateTree(inorder, postorder, nIndex);
		result.clear(); 
        pResult.clear(); 
        dfs(root, 0); 
		int minPos = 0; 
        for(int i=1; i<result.size(); ++i) //result中保存叶子节点的累加值
            if(result[i] < result[minPos]) minPos=i; 
         
        printf("%d\n",pResult[minPos]->data);//presult中是本身的叶子节点
	}
	return 0;
}
