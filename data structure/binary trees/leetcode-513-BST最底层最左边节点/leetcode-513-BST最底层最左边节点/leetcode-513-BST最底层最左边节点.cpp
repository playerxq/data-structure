// leetcode-513-BST最底层最左边节点.cpp : 定义控制台应用程序的入口点。
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
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	void helper(TreeNode* r, int& lev, int& val)
	{
		if (r == NULL)
			return;
		if (r->left == NULL&&r->right == NULL)
		{
			val = r->val;
			lev = 1;
			return;
		}
		int le_lev = 0;
		int le_val;
		int ri_lev = 0;
		int ri_val;
		if (r->left != NULL)
		{
			helper(r->left,le_lev,le_val);
		}
		if (r->right != NULL)
		{
			helper(r->right, ri_lev, ri_val);
		}
		lev = max(le_lev, ri_lev);
		if (lev == le_lev)
			val = le_val;
		else
			val = ri_val;
		lev++;
		return;
	}
	int findBottomLeftValue(TreeNode* root) {
		int lev = 0;
		int val;
		helper(root,lev,val);
		return val;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

