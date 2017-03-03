// leetcode-450-BST删除.cpp : 定义控制台应用程序的入口点。
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
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (!root)
			return NULL;
		if (root->val == key)
		{
			if (!root->right)
			{
				TreeNode* le = root->left;
				delete root;
				return le;
			}
			else
			{
				TreeNode* ri = root->right;
				while (ri->left)
				{
					ri = ri->left;
				}
				swap(root->val,ri->val);
			}
		}
		root->left = deleteNode(root->left,key);
		root->right = deleteNode(root->right, key);
		return root;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

