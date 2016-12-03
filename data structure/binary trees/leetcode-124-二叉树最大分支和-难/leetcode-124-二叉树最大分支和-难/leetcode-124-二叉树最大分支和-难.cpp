// leetcode-124-二叉树最大分支和-难.cpp : 定义控制台应用程序的入口点。
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
	int maxx;
	int dfs(TreeNode* root)
	{
		int ans;
		
		int le,ri;
		le =ri =0;
		int flag = 0;
		if(!root)
		{
			ans = 0;
		}
		else if(!root->left&&!root->right)
		{
			ans = root->val;
		}
		else if(!root->left)
		{
			ans = max(root->val,dfs(root->right)+root->val);
		}
		else if(!root->right)
		{
			ans = max(root->val,dfs(root->left)+root->val);
		}
		else
		{
			le = dfs(root->left);
			ri = dfs(root->right);
			ans = max(root->val,max(root->val+le,root->val+ri));
			if(ans == root->val+le)
				flag = 1;
			else if(ans == root->val+ri)
				flag = 2;
		}
		if(!flag)
			maxx = max(maxx, max(ans,ans+le+ri));
		else if(flag==1)
			maxx = max(maxx, max(ans,ans+ri));
		else
			maxx = max(maxx, max(ans,ans+le));
		return ans;
	}
    int maxPathSum(TreeNode* root) {
        if(!root)
			return 0;
		maxx = INT_MIN;
		int ans = dfs(root);
		return maxx;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	TreeNode root(2);
	TreeNode n1(-1);
	//TreeNode n2(8);
	root.left = &n1;
	/*
	root.right = &n2;
	TreeNode n3(11);
	TreeNode n4(13);
	TreeNode n5(4);
	n1.left = &n3;
	n2.left = &n4;
	n2.right = &n5;
	TreeNode n6(7);
	TreeNode n7(2);
	TreeNode n8(1);
	n3.left = &n6;
	n3.right = &n7;
	n5.right = &n8;
	*/
	Solution s;
	s.maxPathSum(&root);
}

