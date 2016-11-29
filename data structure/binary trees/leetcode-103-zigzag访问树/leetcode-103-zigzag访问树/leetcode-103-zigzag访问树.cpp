// leetcode-103-zigzag访问树.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> level;
        if(root==NULL)
            return res;
        queue<TreeNode*> Q;
        Q.push(root);
        int cnt = 1;
        int temp = 0;
        int nc = 0;
		int flag = 1;
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
				if(!flag)
					std::reverse(level.begin(),level.end());
                res.push_back(level);
                level.clear();
                temp = 0;
                cnt = nc;
                nc=0;
				flag = 1-flag;
            }
        }
        return res;
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

