// leetcode-655-´òÓ¡¶þ²æÊ÷.cpp : Defines the entry point for the console application.
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
	int get_height(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		int left = get_height(root->left), right = get_height(root->right);
		return max(left,right) + 1;
	}
	int get_width(TreeNode* root)
	{
		if (root == NULL)
			return 0;
		int left = get_width(root->left), right = get_width(root->right);
		return 2*max(left, right) + 1;
	}
	void helper(vector<vector<string>>& ans, TreeNode* p, int r, int le, int ri)
	{
		if (!p)
			return;
		int mid = le + (ri-le) / 2;
		ans[r][mid] = to_string(p->val);
		helper(ans,p->left,r+1,le,mid-1);
		helper(ans,p->right,r+1,mid+1,ri);
	}
	vector<vector<string>> printTree(TreeNode* root) {
		int h = get_height(root), w = get_width(root);
		vector<vector<string>> ans(h, vector<string>(w, ""));
		helper(ans, root, 0, 0, w - 1);
		return ans;
	}
};
int main()
{
    return 0;
}

