// leetcode-783-×îÐ¡²îÖµ.cpp : Defines the entry point for the console application.
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
	void preorder(TreeNode* root, vector<int>& ve)
	{
		if (root == NULL)
			return;
		ve.push_back(root->val);
		preorder(root->left,ve);
		preorder(root->right,ve);
	}
	int minDiffInBST(TreeNode* root) {
		if (root == NULL)
			return 0;
		vector<int> ve;
		preorder(root,ve);
		int n = ve.size();
		int minn = INT_MAX;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (abs(ve[i] - ve[j]) < minn)
					minn = abs(ve[i]-ve[j]);
			}
		}
		return minn;
	}
};
int main()
{
	Solution s;
	TreeNode root(4);
	root.left = new TreeNode(2);
	root.right = new TreeNode(6);
	root.left->left = new TreeNode(1);
	root.left->right = new TreeNode(3);
	s.minDiffInBST(&root);
    return 0;
}

