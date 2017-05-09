// leetcode-572-子树匹配.cpp : 定义控制台应用程序的入口点。
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
	vector<int> preKMP(string s)
	{
		int m = s.size();
		vector<int> f(m);
		int j = -1;
		f[0] = -1;
		int i = 1;
		for (; i < m; i++)
		{
			while (j >= 0 && s[i] != s[j + 1])
				j = f[j];
			if (s[i] == s[j + 1])
			{
				j++;
				f[i] = j;
			}
		}
		return f;
	}
	bool kmp(string s1, string s2)
	{
		int n = s1.size();
		int m = s2.size();
		vector<int> f;
		f = preKMP(s2);
		int i = 0;
		int j = -1;
		for (; i < n; i++)
		{
			while (j >= 0 && s1[i] != s2[j + 1])
				j = f[j];
			if (s1[i] == s2[j + 1])
				j++;
			if (j == m - 1)
			{
				return true;
			}
		}
		return false;
	}
	void preorder(TreeNode* root, string& str)
	{
		if (root == NULL)
			return;
		str += '(';
		str += to_string(root->val);
		preorder(root->left, str);
		preorder(root->right, str);
		str += ')';
		return;
	}
	bool isSubtree(TreeNode* s, TreeNode* t) {
		string str1 = "";
		string str2 = "";
		preorder(s, str1);
		preorder(t, str2);
		return kmp(str1, str2);
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

