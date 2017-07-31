// leetcode-652-返回相同子树.cpp : Defines the entry point for the console application.
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
	string seria(TreeNode* root, unordered_map<string, vector<TreeNode*>>& mm)
	{
		if (root == NULL)
			return "";
		string s = "(" + seria(root->left, mm) + to_string(root->val) + seria(root->right, mm) + ")";
		mm[s].push_back(root);
		return s;
	}
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		unordered_map<string, vector<TreeNode*>> mm;
		vector<TreeNode*> res;
		seria(root,mm);
		for (auto it = mm.begin(); it != mm.end(); it++)
		{
			if (it->second.size() > 1)
			{
				res.push_back(it->second[0]);
			}
		}
		return res;
	}
};
int main()
{
    return 0;
}

