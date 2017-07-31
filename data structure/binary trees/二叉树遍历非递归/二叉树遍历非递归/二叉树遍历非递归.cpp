// 二叉树遍历非递归.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
typedef struct node
{
	int data;
	struct node* lchild;  //左孩子  
	struct node* rchild;  //右孩子  
}BTNode;
vector<int> Inorder(BTNode* root)
{
	vector<int> res;
	if (root == NULL)
		return res;
	BTNode* cur = root;
	stack<BTNode*> s;
	while (!s.empty() || cur)
	{
		while (cur)
		{
			s.push(cur);
			cur = cur->lchild;
		}
		if (!s.empty())
		{
			cur = s.top();
			res.push_back(cur->data);
			s.pop();
			cur = cur->rchild;
		}
	}
	return res;
}
vector<int> PreOrder(BTNode* root)
{
	vector<int> res;
	if (root == NULL)
		return res;
	BTNode* cur = root;
	stack<BTNode*> s;
	while (!s.empty() || cur)
	{
		while (cur)
		{
			res.push_back(cur->data);
			s.push(cur);
			cur = cur->lchild;
		}
		if (!s.empty())
		{
			cur = s.top();
			s.pop();
			cur = cur->rchild;
		}
	}
	return res;
}
vector<int> PostOrder(BTNode* root)
{
	vector<int> res;
	if (root == NULL)
		return res;
	BTNode* cur = root;
	BTNode* plast = NULL;//上次访问的节点
	stack<BTNode*> s;
	while (cur)
	{
		s.push(cur);
		cur = cur->lchild;
	}
	while (!s.empty())
	{
		cur = s.top();
		s.pop();
		if (cur->rchild == NULL || cur->rchild == plast)
		{
			res.push_back(cur->data);
			plast = cur;
		}
		else
		{
			s.push(cur);
			cur = cur->rchild;
			while (cur)
			{
				s.push(cur);
				cur = cur->lchild;
			}
		}
	}
	return res;
}
BTNode* init(int n, int mm)
{
	if (n > mm)
		return NULL;
	BTNode* root = new BTNode();
	root->data = n;
	root->lchild = init(n+1,(mm-n)/2+n);
	root->rchild = init((mm - n) / 2 + n +1,mm);
	return root;
}
int main()
{
	BTNode* root;
	root = init(1,10);
	vector<int> res;
	res = PreOrder(root);
	res.clear();
	res = Inorder(root);
	res.clear();
	res = PostOrder(root);
	res.clear();
    return 0;
}

