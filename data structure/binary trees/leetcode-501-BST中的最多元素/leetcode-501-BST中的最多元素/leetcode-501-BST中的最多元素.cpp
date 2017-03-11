// leetcode-501-BST中的最多元素.cpp : 定义控制台应用程序的入口点。
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
	void in_tranverse(TreeNode* root, int& maxfre, int& cnt, int& pre)
	{
		if (root == NULL)
			return;
		int mm = 0;
		in_tranverse(root->left, mm, cnt, pre);
		maxfre = max(maxfre,mm);
		if (root->val == pre)
		{
			cnt++;
			maxfre = max(maxfre, cnt);
		}
		else
		{
			cnt = 1;
			maxfre = max(maxfre, cnt);
		}
		pre = root->val;
		in_tranverse(root->right,maxfre,cnt,pre);
	}
	void helper(TreeNode* root, int maxfre, int& cnt, int& pre, vector<int>& res)
	{
		if (root == NULL)
			return;
		helper(root->left,maxfre,cnt,pre,res);
		if (pre == root->val)
		{
			cnt++;
			if (cnt == maxfre)
			{
				res.push_back(root->val);
			}
		}
		else
		{
			cnt = 1;
			if (cnt == maxfre)
			{
				res.push_back(root->val);
			}
		}
		pre = root->val;
		helper(root->right, maxfre, cnt, pre, res);
	}
	vector<int> findMode(TreeNode* root) {
		int maxfre = 0;
		int pre;
		int cnt = 0;
		in_tranverse(root,maxfre,cnt,pre);
		vector<int> res;
		cnt = 0;
		helper(root,maxfre,cnt,pre,res);
		return res;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	TreeNode* root = new TreeNode(1);
	root->right = new TreeNode(2);
	//root->right->left = new TreeNode(2);
	Solution s;
	s.findMode(root);
	return 0;
}

