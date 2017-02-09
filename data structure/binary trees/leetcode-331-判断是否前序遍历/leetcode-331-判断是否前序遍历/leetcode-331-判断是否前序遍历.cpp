// leetcode-331-判断是否前序遍历.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;

class Solution {
public:
	bool dfs(vector<string>& node, int st, int& ed)
	{
		if (node[st] == "#")
		{
			ed = st;
			return true;
		}
		else
		{
			int x = st;
			if (dfs(node, st + 1, x))
			{
				int y = x;
				if (dfs(node, y + 1, x))
				{
					ed = x;
					return true;
				}
			}
			return false;
		}
	}
	bool isValidSerialization(string preorder) {
		if (preorder.size() == 0)
			return true;
		
		vector<string> node;
		stringstream s(preorder);
		string token;
		while (getline(s, token, ','))
		{
			node.push_back(token);
		}
		if (node.size() == 1)
		{
			if (node[0] == "#")
				return true;
			return false;
		}
		if (node.size() % 2 == 0)
			return false;
		int ed = 0;
		if (dfs(node, 0, ed)&&ed==node.size()-1)
			return true;
		return false;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	s.isValidSerialization("1,#,#,#,#");
	return 0;
}

