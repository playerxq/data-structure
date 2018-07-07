// leetcode-863-Ê÷¾àÀë.cpp : Defines the entry point for the console application.
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
	void make_graph(vector<vector<int>>& g, TreeNode* root)
	{
		if (root->left)
		{
			g[root->val][root->left->val] = 1;
			g[root->left->val][root->val] = 1;
			make_graph(g,root->left);
		}
		if (root->right)
		{
			g[root->val][root->right->val] = 1;
			g[root->right->val][root->val] = 1;
			make_graph(g, root->right);
		}
	}
	vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
		vector<vector<int>> graph(501, vector<int>(501, -1));
		make_graph(graph,root);
		vector<int> ve;
		ve.push_back(target->val);
		vector<int> visited(501, 0);
		visited[target->val] = 1;
		for (int i = 0; i < K; i++)
		{
			vector<int> nx;
			for (int j = 0; j < ve.size(); j++)
			{
				for (int s = 0; s < 501; s++)
				{
					if (graph[ve[j]][s] == 1 && visited[s] == 0)
					{
						nx.push_back(s);
						visited[s] = 1;
					}
				}
			}
			ve = nx;
		}
		return ve;
	}
};
int main()
{
    return 0;
}

