// leetcode-515-BST-BFS.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;

class Solution
{
public:
	vector<int> largestValues(TreeNode* root)
	{
		vector<int> res;
		if (root == NULL)
			return res;
		queue<TreeNode*> q;
		queue<int> level;
		q.push(root);
		level.push(0);
		int m = -1;
		while (!q.empty())
		{
			TreeNode* r = q.front();
			q.pop();
			int l = level.front();
			level.pop();
			if (r->left)
			{
				q.push(r->left);
				level.push(l+1);
			}
			if (r->right)
			{
				q.push(r->right);
				level.push(l+1);
			}
			if (l > m)
			{
				m = l;
				res.push_back(r->val);
			}
			else
			{
				res[l] = max(res[l],r->val);
			}
		}
		return res;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

