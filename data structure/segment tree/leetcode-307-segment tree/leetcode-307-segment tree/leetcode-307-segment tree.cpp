// leetcode-307-segment tree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;


class NumArray {
public:
	vector<int> sum;
	int sz;
	NumArray(const vector<int>& nums) :sum(nums.size() << 2, 0) {
		sz = nums.size();
		for (int i = 0; i < sz; i++)
			update(i,nums[i]);
	}
	void Tree_update(int rt, int l, int r, int L, int R, int val)
	{
		if (L <= l&&R >= r)
			sum[rt] = val;
		else
		{
			int mid = (l + r) >> 1;
			if (R > l&&L < mid)
				Tree_update(rt<<1,l,mid,L,R,val);
			if (R > mid&&L < r)
				Tree_update(rt<<1|1,mid,r,L,R,val);
			sum[rt] = sum[rt << 1] + sum[rt<<1|1];
			return;
		}
	}
	int Tree_query(int rt, int l, int r, int L, int R)
	{
		if (L <= l&&R >= r)
			return sum[rt];
		int mid = (l + r) >> 1;
		int ret = 0;
		if (R > l&&L < mid)
			ret += Tree_query(rt << 1, l, mid, L, R);
		if (R > mid&&L < r)
			ret+= Tree_query(rt << 1 | 1, mid, r, L, R);
		return ret;
	}
	void update(int i, int val) {
		Tree_update(1,0,sz,i,i+1,val);
	}

	int sumRange(int i, int j) {
		return Tree_query(1,0,sz,i,j+1);
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

