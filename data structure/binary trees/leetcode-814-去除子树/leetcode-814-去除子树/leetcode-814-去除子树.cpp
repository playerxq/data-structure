// leetcode-814-È¥³ý×ÓÊ÷.cpp : Defines the entry point for the console application.
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
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	TreeNode* dfs(TreeNode* root)
	{
		if (root == NULL)
			return NULL;
		if (root->val == 1)
		{
			root->left = dfs(root->left);
			root->right = dfs(root->right);
			return root;
		}
		else
		{
			root->left = dfs(root->left);
			root->right = dfs(root->right);
			if (root->left == NULL&&root->right == NULL)
				return NULL;
			return root;
		}
	}
	TreeNode* pruneTree(TreeNode* root) {
		if (root == NULL)
			return NULL;
		return dfs(root);
	}
};
int main()
{
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(0);
	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(0);
	//root->left->left->left = new TreeNode(0);
	root->right = new TreeNode(1);
	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(1);
	Solution s;
	root = s.pruneTree(root);
	root = NULL;
    return 0;
}

