// leetcode-653-二叉树求节点和.cpp : Defines the entry point for the console application.
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
	bool findTarget(TreeNode* root, int k) {
		vector<int> nums;
		inorder(root, nums);
		return findTargetInSortedArray(nums, k);
	}

private:
	void inorder(TreeNode* node, vector<int>& nums) {
		if (!node) return;
		inorder(node->left, nums);
		nums.push_back(node->val);
		inorder(node->right, nums);
	}

	bool findTargetInSortedArray(vector<int> a, int target) {
		for (int i = 0, j = a.size() - 1; i < j;) {
			int sum = a[i] + a[j];
			if (sum == target) {
				return true;
			}
			else if (sum < target) {
				i++;
			}
			else {
				j--;
			}
		}

		return false;
	}
};
int main()
{
    return 0;
}

