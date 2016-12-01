// leetcode-116-117-������ָ��ָ���ֵܽڵ�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
//��ȫ������
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)
			return;
		if(root->left)
			root->left->next = root->right;
		if(root->next&&root->next->left)
			root->right->next = root->next->left;
		connect(root->left);
		connect(root->right);
    }
};
//һ�������
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)
			return;
		if(root->right)
		{
			if(root->next&&root->next->left)
				root->right->next = root->next->left;
			else if(root->next&&root->next->left==NULL&&root->next->right)
				root->right->next = root->next->right;
			else if(root->next&&root->next->left==NULL&&root->next->right==NULL)
			{
				TreeLinkNode* cur = root->next;
				while(cur&&cur->left==NULL&&cur->right==NULL)
					cur = cur->next;
				if(cur==NULL)
					root->right->next = NULL;
				else if(cur->left)
					root->right->next = cur->left;
				else
					root->right->next = cur->right;
			}
			else
				root->right->next = NULL;
		}
		if(root->left)
		{
			if(root->right)
				root->left->next = root->right;
			else
			{
				if(root->next&&root->next->left)
					root->left->next = root->next->left;
				else if(root->next&&root->next->left==NULL&&root->next->right)
					root->left->next = root->next->right;
				else if(root->next&&root->next->left==NULL&&root->next->right==NULL)
				{
					TreeLinkNode* cur = root->next;
					while(cur&&cur->left==NULL&&cur->right==NULL)
						cur = cur->next;
					if(cur==NULL)
						root->left->next = NULL;
					else if(cur->left)
						root->left->next = cur->left;
					else
						root->left->next = cur->right;
				}
				else
					root->left->next = NULL;
			}
		}
		connect(root->right);
		connect(root->left);
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

