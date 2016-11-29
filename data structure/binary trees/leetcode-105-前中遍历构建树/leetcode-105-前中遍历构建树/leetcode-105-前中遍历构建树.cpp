// leetcode-105-前中遍历构建树.cpp : 定义控制台应用程序的入口点。
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if((preorder.size()==0&&inorder.size()!=0)||(preorder.size()!=0&&inorder.size()==0))
			return NULL;
		if(preorder.size()==0&&inorder.size()==0)
			return NULL;
		TreeNode* root = new TreeNode(preorder[0]);
		TreeNode* ret = root;
		vector<TreeNode*> st;
		st.push_back(root);
		size_t i = 0;
		for(size_t p = 0;p<preorder.size()-1;p++)
		{
			if(preorder[p]!=inorder[i])
			{
				ret->left = new TreeNode(preorder[p+1]);
				ret = ret->left;
				st.push_back(ret);
			}
			else
			{
				while(!st.empty()&&st.back()->val==inorder[i])
				{
					ret = st.back();
					st.pop_back();
					i++;
				}
				if(p<preorder.size()-1)
				{
					ret->right = new TreeNode(preorder[p+1]);
					ret = ret->right;
					st.push_back(ret);
				}
			}
		}
		return root;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

