// leetcode-538-BST2GreaterTree.cpp : 定义控制台应用程序的入口点。
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
	stack<TreeNode*> st;
	void inorder(TreeNode* r)
	{
		if (r == NULL)
			return;
		inorder(r->left);
		st.push(r);
		inorder(r->right);
	}
	TreeNode* convertBST(TreeNode* root) {
		if (root == NULL)
			return root;
		inorder(root);
		int sum = 0;
		while (!st.empty())
		{
			int temp = st.top()->val;
			st.top()->val += sum;
			sum += temp;
			st.pop();
		}
		return root;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

