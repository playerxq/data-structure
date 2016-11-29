// leetcode-101-102-104.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//判断对称树
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
        return true;
        vector<TreeNode*> v1;
        vector<TreeNode*> v2;
        if(root->left!=NULL)
            v1.push_back(root->left);
        if(root->right!=NULL)
            v2.push_back(root->right);
        while(!v1.empty()&&!v2.empty())
        {
            TreeNode* p = v1.back();
            v1.pop_back();
            TreeNode* q = v2.back();
            v2.pop_back();
            if(p->val!=q->val)
                return false;
            if((p->left!=NULL&&q->right==NULL)||(p->left==NULL&&q->right!=NULL)||(p->right!=NULL&&q->left==NULL)||(p->right==NULL&&q->left!=NULL))
                return false;
            if(p->left!=NULL)
                v1.push_back(p->left);
            if(q->right!=NULL)
                v2.push_back(q->right);
            if(p->right!=NULL)
                v1.push_back(p->right);
            if(q->left!=NULL)
                v2.push_back(q->left);
        }
        if(!v1.empty()||!v2.empty())
            return false;
        return true;
    }
};
//层次化遍历树
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> level;
        if(root==NULL)
            return res;
        queue<TreeNode*> Q;
        Q.push(root);
        int cnt = 1;
        int temp = 0;
        int nc = 0;
        while(!Q.empty())
        {
            TreeNode* cur = Q.front();
            Q.pop();
            temp++;
            level.push_back(cur->val);
            if(cur->left)
            {
                Q.push(cur->left);
                nc++;
            }
            if(cur->right)
            {
                Q.push(cur->right);
                nc++;
            }
            if(temp==cnt)
            {
                res.push_back(level);
                level.clear();
                temp = 0;
                cnt = nc;
                nc=0;
            }
        }
        return res;
    }
};
//求树高
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        queue<TreeNode*> Q;
        Q.push(root);
        int res = 0;
        int cnt = 1;
        int temp = 0;
        int nc = 0;
        while(!Q.empty())
        {
            TreeNode* cur = Q.front();
            Q.pop();
            temp++;
            if(cur->left)
            {
                Q.push(cur->left);
                nc++;
            }
            if(cur->right)
            {
                Q.push(cur->right);
                nc++;
            }
            if(temp==cnt)
            {
                temp = 0;
                cnt = nc;
                nc=0;
                res++;
            }
        }
        return res;
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

