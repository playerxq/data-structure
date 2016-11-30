// leetcode-111-求最短根叶距离.cpp : 定义控制台应用程序的入口点。
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
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        return get_min_dis(root);
    }
    int get_min_dis(TreeNode* root)
    {
        if(!root)
            return 0;
        int le = get_min_dis(root->left);
        int ri = get_min_dis(root->right);
        if(root->left!=NULL&&root->right!=NULL)
            return min(le,ri)+1;
        else if(root->left!=NULL)
            return le+1;
        else
            return ri+1;
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

