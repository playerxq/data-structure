// leetcode-235-LCA.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
			return root;
		if(p->val>q->val)
		{
		    TreeNode* tt = q;
		    q = p;
		    p = tt;
		}
		if(p->val<=root->val&&q->val>=root->val)
			return root;
		else if(p->val<root->val&&q->val<root->val)
			return lowestCommonAncestor(root->left,p,q);
		else
			return lowestCommonAncestor(root->right,p,q);
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

