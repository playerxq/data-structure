// leetcode-222-BST节点个数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {

public:

    int countNodes(TreeNode* root) {

        if(!root) return 0;

        int hl=0, hr=0;

        TreeNode *l=root, *r=root;

        while(l) {hl++;l=l->left;}

        while(r) {hr++;r=r->right;}

        if(hl==hr) return pow(2,hl)-1;

        return 1+countNodes(root->left)+countNodes(root->right);

    }

};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

