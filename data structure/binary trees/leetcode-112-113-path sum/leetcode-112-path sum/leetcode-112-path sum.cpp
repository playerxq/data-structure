// leetcode-112-path sum.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//判断是否有路径
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
		if(!root&&sum!=0)
			return false;
		else if(!root&&sum==0)
			return false;
		else if(!root->left&&!root->right&&sum==root->val)
			return true;
		return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);
    }
};
//打印所有路径
class Solution {
public:
	void dfs(TreeNode* root, vector<vector<int>>& res, vector<int>& temp,int sum)
	{
		if(!root&&sum!=0)
			return;
		if(!root&&sum==0)
			return;
		else if(!root->left&&!root->right&&sum==root->val)
		{
			temp.push_back(root->val);
			res.push_back(temp);
			temp.pop_back();
			return;
		}
		else if(!root->left&&!root->right&&sum!=root->val)
		{
			return;
		}
		temp.push_back(root->val);
		dfs(root->left,res,temp,sum-root->val);
		dfs(root->right,res,temp,sum-root->val);
		temp.pop_back();
	}
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
		vector<int> temp;
		dfs(root,res,temp,sum);
		return res;
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

