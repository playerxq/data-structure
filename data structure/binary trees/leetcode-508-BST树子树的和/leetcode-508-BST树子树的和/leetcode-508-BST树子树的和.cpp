// leetcode-508-BST树子树的和.cpp : 定义控制台应用程序的入口点。
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
	int helper(TreeNode *r, unordered_map<int, int> &counts, int& maxCount)
	{
		if (r == NULL)
			return 0;
		int sum = r->val;
		sum+=helper(r->left, counts, maxCount);
		sum+=helper(r->right, counts, maxCount);
		++counts[sum];
		maxCount = max(maxCount,counts[sum]);
		return sum;
	}
	vector<int> findFrequentTreeSum(TreeNode* root) {
		unordered_map<int, int> counts;
		int maxCount = 0;
		helper(root, counts, maxCount);
		vector<int> maxSums;
		for (const auto& x : counts){
			if (x.second == maxCount) maxSums.push_back(x.first);
		}
		return maxSums;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

