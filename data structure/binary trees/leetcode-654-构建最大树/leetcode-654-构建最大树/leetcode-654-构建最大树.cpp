// leetcode-654-构建最大树.cpp : Defines the entry point for the console application.
//
/*
We scan numbers from left to right, build the tree one node by one step;
We use a stack to keep some (not all) tree nodes and ensure a decreasing order;
For each number, we keep pop the stack until empty or a bigger number; 
The bigger number (if exist, it will be still in stack) is current number's root, 
and the last popped number (if exist) is current number's left child (temporarily, this relationship may change in the future); 
Then we push current number into the stack.
*/
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
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		vector<TreeNode*> s;
		int n = nums.size();
		for (int i = 0; i < n; i++)
		{
			TreeNode* cur = new TreeNode(nums[i]);
			TreeNode* l = nullptr;
			while (!s.empty() && s.back()->val < nums[i])
			{
				l = s.back();
				s.pop_back();
			}
			cur->left = l;
			if (!s.empty())
				s.back()->right = cur;
			s.push_back(cur);
		}
		return s.front();
	}
};
int main()
{
    return 0;
}

