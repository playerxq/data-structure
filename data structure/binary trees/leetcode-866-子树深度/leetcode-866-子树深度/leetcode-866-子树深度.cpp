// leetcode-866-×ÓÊ÷Éî¶È.cpp : Defines the entry point for the console application.
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
	int depth(TreeNode* root)
	{
		if (!root)
			return -1;
		return max(depth(root->left), depth(root->right)) + 1;
	}
	bool dfs(TreeNode*& res, TreeNode* root, int d, int dep)
	{
		if (!root)
			return false;
		if (dep == d)
		{
			res = root;
			return true;
		}
		bool le = dfs(res, root->left, d, dep + 1);
		bool ri = dfs(res, root->right, d, dep + 1);
		if (le&&ri)
		{
			res = root;
		}
		return le || ri;
	}
	TreeNode* subtreeWithAllDeepest(TreeNode* root) {
		if (!root)
			return NULL;
		int d = depth(root);
		TreeNode* res = root;
		dfs(res,root,d,0);
		return res;
	}
};
int main()
{
    return 0;
}

