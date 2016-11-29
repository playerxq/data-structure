// leetcode-106-中后遍历构建树.cpp : 定义控制台应用程序的入口点。
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
    unordered_map<int, int> um;
	TreeNode* dfs(unordered_map<int, int>& um,vector<int>& inorder, int in_st, int in_ed, vector<int>& postorder, int post_st, int post_ed)
	{
		if((in_st>in_ed)||(post_st>post_ed))
			return NULL;
		TreeNode* root = new TreeNode(postorder[post_ed]);
		int idx = um[postorder[post_ed]];
		root->left = dfs(um,inorder,in_st,idx-1,postorder,post_st,post_st+idx-in_st-1);
		root->right = dfs(um,inorder,idx+1,in_ed,postorder,post_st+idx-in_st,post_ed-1);
		return root;
	}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size(), i = 0;
        for(int val : inorder) um[val] = i++;
		TreeNode* root = dfs(um,inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
		return root;
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

