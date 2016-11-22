// uva-699-fall leaf.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
int a[100000];

typedef struct Node
{
	int v;
	int index_h;//水平偏移
	struct Node* left;
	struct Node* right;
	Node(int a):v(a),left(0),right(0),index_h(0){}
} Node;

Node* creat()
{
	int num;
	cin>>num;
	if(num==-1)
		return 0;
	Node* root = new Node(num);
	root->left = creat();
	root->right = creat();
	return root;
}



void caculate_index(Node* root,int mid)
{
	if(root==0)
		return;
	root->index_h = mid;
	a[root->index_h]+=root->v;
	caculate_index(root->left,mid-1);
	caculate_index(root->right,mid+1);
	
}

int main()
{
	int cas = 0;
	Node* root;
	while(root = creat())
	{
		memset(a,0,sizeof(a));
		int i = 500;
		caculate_index(root,i);
		while(a[i])i--;
		cout<<"Case "<<++cas<<":"<<endl;
		for(i++;a[i];i++)
		{
			cout<<a[i];  
            if(a[i+1])cout<<" ";  
		}
		cout<<endl<<endl;
	}
	return 0;
}

