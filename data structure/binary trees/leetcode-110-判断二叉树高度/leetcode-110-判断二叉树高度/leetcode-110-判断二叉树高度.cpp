// leetcode-110-判断二叉树高度.cpp : 定义控制台应用程序的入口点。
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
    bool isBalanced(TreeNode* root) {
        return getBalancedHeight(root) == 0 ? false : true;
    }
	int getBalancedHeight(TreeNode* root) 
	{
		if(!root)
			return 1;
		int left_height = getBalancedHeight(root->left);
        if (left_height == 0) return 0;
        
        int right_height = getBalancedHeight(root->right);
        if (right_height == 0) return 0;
        
        int diff = abs(left_height - right_height);
        if (diff > 1) return 0;
        else return (1 + max(left_height, right_height));
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

