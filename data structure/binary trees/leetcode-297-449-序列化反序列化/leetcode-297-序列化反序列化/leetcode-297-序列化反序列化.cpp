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
class Codec1 {

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
class Codec {
private:
	string getNextNode(string const& data, int& offset)
	{
		int end = data.find(',',offset);
		if (end == string::npos)
		{
			end = data.length();
		}
		string res = data.substr(offset,end-offset);
		offset = end + 1;
		return res;
	}
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string res = "";
		if (!root)
			return res;
		queue<TreeNode*> Q;
		Q.push(root);
		res += to_string(root->val);
		res += ',';
		while (!Q.empty())
		{
			TreeNode* node = Q.front();
			if (node->left)
			{
				res += to_string(node->left->val);
				res += ',';
				Q.push(node->left);
			}
			else
				res += "#,";
			if (node->right)
			{
				res += to_string(node->right->val);
				res += ',';
				Q.push(node->right);
			}
			else
				res += "#,";
			Q.pop();
		}
		int i = res.size() - 1;
		for (--i; i >= 0 && res[i] == '#'; i -= 2);
		return res.substr(0, i + 1);
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		TreeNode* root = NULL;
		if (data.size() == 0)
			return root;
		queue<TreeNode*> Q;
		int offset = 0;
		string ss = getNextNode(data,offset);
		int val = stoi(ss);
		root = new TreeNode(val);
		Q.push(root);
		while (!Q.empty())
		{
			TreeNode* node = Q.front();
			if (offset < data.length())
			{
				string sss = getNextNode(data,offset);
				if (sss != "#")
				{
					int vall = stoi(sss);
					node->left = new TreeNode(vall);
					Q.push(node->left);
				}
			}
			if (offset < data.length())
			{
				string sss = getNextNode(data, offset);
				if (sss != "#")
				{
					int vall = stoi(sss);
					node->right = new TreeNode(vall);
					Q.push(node->right);
				}
			}
			Q.pop();
		}
		return root;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

