// leetcode-297-序列化反序列化.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Codec {

	// Encodes a tree to a single string.
public:
	string serialize(TreeNode* root) {
		if (root == NULL)
		{
			return "#";
		}
		return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		return my_deserialize(data);
	}
	TreeNode* my_deserialize(string& data)
	{
		if (data[0] == '#')
		{
			if (data.size() > 1)
				data = data.substr(2);
			return NULL;
		}
		else
		{
			TreeNode* node = new TreeNode(helper(data));
			node->left = my_deserialize(data);
			node->right = my_deserialize(data);
			return node;
		}
	}
	int helper(string& data)
	{
		int pos = data.find(',');
		int val = stoi(data.substr(0, pos));
		data = data.substr(pos + 1);
		return val;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

