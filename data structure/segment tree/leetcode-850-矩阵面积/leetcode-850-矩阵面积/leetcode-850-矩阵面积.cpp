// leetcode-850-¾ØÕóÃæ»ý.cpp : Defines the entry point for the console application.
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
struct node
{
	long long x1, x2, h;
	int f;
}e[202];
int n, opl, opr, flag;
int col[801];
long long Hash[201], sum[1601];

bool cmp(node a, node b) { return a.h<b.h; }
inline void up(int k, int l, int r)
{
	if (col[k]) sum[k] = Hash[r + 1] - Hash[l];
	else sum[k] = sum[k << 1] + sum[(k << 1) + 1];
}
inline void change(int k, int l, int r)
{
	if (l >= opl&&r <= opr)
	{
		col[k] += flag;
		up(k, l, r);
		return;
	}
	int m = (l + r) >> 1;
	if (opl <= m) change(k << 1, l, m);
	if (opr>m) change((k << 1) + 1, m + 1, r);
	up(k, l, r);
}
class Solution {
public:
	int rectangleArea(vector<vector<int>>& rectangles) {
		n = rectangles.size();
		long long ans = 0;
		int md = (int)pow(10, 9) + 7;
		for (int i = 1; i <= n; i++)
		{
			long long x1 = rectangles[i - 1][0];
			long long x2 = rectangles[i - 1][2];
			long long y1 = rectangles[i - 1][1];
			long long y2 = rectangles[i - 1][3];
			e[i * 2 - 1].x1 = e[i * 2].x1 = x1;
			e[i * 2 - 1].x2 = e[i * 2].x2 = x2;
			e[i * 2 - 1].h = y1; e[i * 2].h = y2;
			Hash[i * 2 - 1] = x1; Hash[i * 2] = x2;
			e[i * 2 - 1].f = 1; e[i * 2].f = -1;
		}
		sort(Hash + 1, Hash + 2 * n + 1);
		sort(e + 1, e + 2 * n + 1, cmp);
		for (int i = 1; i <= 2 * n; i++)
		{
			opl = lower_bound(Hash + 1, Hash + 2 * n + 1, e[i].x1) - Hash;
			opr = lower_bound(Hash + 1, Hash + 2 * n + 1, e[i].x2) - Hash - 1;
			flag = e[i].f;
			change(1, 1, 2 * n);
			ans = (ans+(sum[1] * (e[i + 1].h - e[i].h)))%md;
		}
		ans = ans%md;
		return ans;
	}
};
int main()
{
	Solution s;
	vector<vector<int>> ve = { { 0,0,1000000000,1000000000 }};
	s.rectangleArea(ve);
    return 0;
}

