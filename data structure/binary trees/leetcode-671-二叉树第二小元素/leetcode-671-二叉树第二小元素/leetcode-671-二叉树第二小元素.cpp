// leetcode-671-二叉树第二小元素.cpp : Defines the entry point for the console application.
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
	int minval(TreeNode* p, int minn)
	{
		if (p == NULL)
			return INT_MAX;
		if (p->val != minn)
			return p->val;
		int le = minval(p->left, minn);
		int ri = minval(p->right, minn);
		return min(le, ri);
	}
	int findSecondMinimumValue(TreeNode* root) {
		if (root == NULL)
			return -1;
		int ans = minval(root, root->val);
		if (ans == INT_MAX)
			return -1;
		return ans;
	}
};
int main()
{
    return 0;
}

