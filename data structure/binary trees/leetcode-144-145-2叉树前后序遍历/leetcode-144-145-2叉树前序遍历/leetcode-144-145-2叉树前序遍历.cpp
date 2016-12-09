// leetcode-144-145-2叉树前序遍历.cpp : 定义控制台应用程序的入口点。
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
//preorder
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
		if(root==NULL)
			return res;
		TreeNode* cur = root;
		stack<TreeNode*> ss;
		while(cur!=NULL)
		{
			ss.push(cur);
			res.push_back(cur->val);
			cur = cur->left;
			if(cur==NULL)
			{
				while(!ss.empty()&&ss.top()->right==NULL)
					ss.pop();
				if(ss.empty())
					break;
				else
				{
					cur = ss.top()->right;
					ss.pop();
				}
			}
		}
		return res;
    }
};
//postorder
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
		if(root==NULL)
			return res;
		stack<TreeNode*> ss;
		TreeNode* cur = root;
		while(cur!=NULL)
		{
			ss.push(cur);
			res.push_back(cur->val);
			cur = cur->right;
			if(cur==NULL)
			{
				while(!ss.empty()&&ss.top()->left==NULL)
					ss.pop();
				if(ss.empty())
					break;
				else
				{
					cur = ss.top()->left;
					ss.pop();
				}
			}
		}
		reverse(res.begin(),res.end());
		return res;
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

