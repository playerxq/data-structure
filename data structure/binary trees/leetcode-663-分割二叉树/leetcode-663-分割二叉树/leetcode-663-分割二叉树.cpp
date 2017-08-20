// leetcode-663-·Ö¸î¶þ²æÊ÷.cpp : Defines the entry point for the console application.
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
	long long int sumTree(TreeNode* r, unordered_map<TreeNode*, long long int> &treeSums) {
		if (r == nullptr) return 0LL;

		treeSums[r] = sumTree(r->left, treeSums) + sumTree(r->right, treeSums) + r->val;
		return treeSums[r];
	}
	void preorder(TreeNode* r, unordered_map<TreeNode*, long long int> &treeSums, const long long int totalSum, bool &canPartition) {
		if (r == nullptr || canPartition) return;

		if (totalSum == 2 * treeSums[r]) canPartition = true;

		preorder(r->left, treeSums, totalSum, canPartition);
		preorder(r->right, treeSums, totalSum, canPartition);
	}
	bool checkEqualTree(TreeNode* root) {
		if (!root)
			return false;
		if ((root->left == nullptr) && (root->right == nullptr)) return false;
		unordered_map<TreeNode*, long long int> treeSums;
		long long int totalSum = sumTree(root, treeSums);
		if (totalSum % 2 == 1LL) return false;
		bool canPartition = false;

		preorder(root, treeSums, totalSum, canPartition);

		return canPartition;
	}
};
int main()
{
    return 0;
}

