// leetcode-834-Ê÷µÄ±éÀú.cpp : Defines the entry point for the console application.
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

class Solution {
public:
	void post_order(int cur, vector<vector<int>>& mp, vector<int>& child, vector<int>& res, vector<int>& vis)
	{
		if (vis[cur])
			return;
		vis[cur] = 1;
		for (int i = 0; i < mp[cur].size(); i++)
		{
			if (vis[mp[cur][i]])
				continue;
			post_order(mp[cur][i],mp,child,res, vis);
			child[cur] += child[mp[cur][i]];
			res[cur] += (child[mp[cur][i]] + res[mp[cur][i]]);
		}
		child[cur]++;
		return;
	}
	void pre_order(int cur, int parent, int N, vector<vector<int>>& mp, vector<int>& child, vector<int>& res, vector<int>& vis)
	{
		if (vis[cur])
			return;
		vis[cur] = 1;
		res[cur] = res[parent] + N - 2 * child[cur];
		for (int i = 0; i < mp[cur].size(); i++)
		{
			if (vis[mp[cur][i]])
				continue;
			pre_order(mp[cur][i],cur,N,mp,child,res,vis);
		}
		return;
	}
	vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
		vector<vector<int>> mp(N);
		for (int i = 0; i < edges.size(); i++)
		{
			mp[edges[i][0]].push_back(edges[i][1]);
			mp[edges[i][1]].push_back(edges[i][0]);
		}
		vector<int> res(N,0);
		vector<int> child(N,0);
		vector<int> vis(N,0);
		post_order(0, mp, child, res, vis);
		vis.assign(N,0);
		vis[0] = 1;
		for (int i = 0; i < mp[0].size(); i++)
		{
			pre_order(mp[0][i],0,N,mp,child,res,vis);
		}
		return res;
	}
};
int main()
{
	Solution s;
	vector<vector<int>> edges = { {0,1},{0,2},{2,3},{2,4},{2,5} };
	//vector<vector<int>> edges = { { 1,0 } };
	s.sumOfDistancesInTree(6,edges);
    return 0;
}

