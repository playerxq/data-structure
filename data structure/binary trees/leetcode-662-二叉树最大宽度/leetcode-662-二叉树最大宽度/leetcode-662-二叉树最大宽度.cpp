// leetcode-662-二叉树最大宽度.cpp : Defines the entry point for the console application.
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
	void dfs(TreeNode* root, int id, int dep, vector<int>& le, int& res)
	{
		if (root == NULL)
			return;
		if (dep >= le.size())
			le.push_back(id);
		res = max(res, id + 1 - le[dep]);
		dfs(root->left, 2 * id, dep + 1, le, res);
		dfs(root->right, 2 * id + 1, dep + 1, le, res);
	}
	int widthOfBinaryTree(TreeNode* root) {
		vector<int> le;
		int res = 0;
		dfs(root, 1, 0, le, res);
		return res;
	}
};
int main()
{
    return 0;
}

