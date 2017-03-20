// leetcode-543-树的直径.cpp : 定义控制台应用程序的入口点。
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
	int maxdep = 0;
	int dfs(TreeNode* r)
	{
		if (r == NULL)
			return 0;
		int le = dfs(r->left);
		int ri = dfs(r->right);
		maxdep = max(maxdep,le+ri);
		return max(le+1,ri+1);
	}
	int diameterOfBinaryTree(TreeNode* root) {
		dfs(root);
		return maxdep;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

