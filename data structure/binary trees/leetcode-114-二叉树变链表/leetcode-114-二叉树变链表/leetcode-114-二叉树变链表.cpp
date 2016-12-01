// leetcode-114-二叉树变链表.cpp : 定义控制台应用程序的入口点。
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
class Solution {
public:
	stack<TreeNode* > mystack;
    void flatten(TreeNode* root) {
        if(!root)
			return;
		if(root->right)
			mystack.push(root->right);
		root->right = root->left;
		root->left = NULL;
		flatten(root->right);
		if(!mystack.empty())
		{
			root->right = mystack.top();
			mystack.pop();
			flatten(root->right);
		}
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

