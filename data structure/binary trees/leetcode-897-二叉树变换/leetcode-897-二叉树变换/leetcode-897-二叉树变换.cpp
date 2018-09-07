// leetcode-897-二叉树变换.cpp : 定义控制台应用程序的入口点。
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
	vector<TreeNode*> tmp;
	TreeNode* increasingBST(TreeNode* root) {
		inorder(root);
		TreeNode* current = tmp[0];
		TreeNode* result = current;
		tmp[0]->left = NULL;
		tmp[0]->right = NULL;
		for (int i = 1;i < tmp.size();i++)
		{
			tmp[i]->left = NULL;
			tmp[i]->right = NULL;
			current->left = NULL;
			current->right = tmp[i];
			current = tmp[i];
		}
		return result;
	}
	void inorder(TreeNode* root)
	{
		if (!root)
			return;
		inorder(root->left);
		tmp.push_back(root);
		inorder(root->right);
	}
};
int main()
{
    return 0;
}

