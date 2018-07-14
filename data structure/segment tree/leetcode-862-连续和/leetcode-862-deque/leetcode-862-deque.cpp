// leetcode-862-deque.cpp : Defines the entry point for the console application.
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
	vector<int> tree;
	void build(vector<int>& A) {
		for (int i = 0; i<A.size() * 2; i++) tree.push_back(INT_MIN);
	}
	void update(int i, int val) {
		i += tree.size() / 2;
		while (i > 0) {
			tree[i] = max(tree[i], val);
			i /= 2;
		}
	}
	int get(int a, int b) {
		int ans = INT_MIN;
		a += tree.size() / 2;
		b += tree.size() / 2;
		while (a <= b) {
			if (a % 2 == 1) {
				ans = max(ans, tree[a]);
				a++;
			}
			if (b % 2 == 0) {
				ans = max(ans, tree[b]);
				b--;
			}
			a /= 2;
			b /= 2;
		}
		return ans;
	}
	int shortestSubarray(vector<int>& A, int K) {
		A.insert(A.begin(), 0);
		vector<long> v;
		long cnt = 0;
		int ans = INT_MAX;
		build(A);
		unordered_map<int, int> mp;
		for (int i = 0; i < A.size(); i++)
		{
			cnt += A[i];
			if (cnt >= K) ans = min(ans, i + 1);
			int idx = lower_bound(v.begin(), v.end(), cnt - K) - v.begin();
			if (idx == v.size() && cnt >= K) return 1;
			if (!v.empty() && v[idx] > cnt - K) idx--;
			if (idx >= 0 && v.size() > idx && v[idx] <= cnt - K) ans = min(ans, i - get(0, idx));
			int idxx = lower_bound(v.begin(), v.end(), cnt) - v.begin();
			if (idxx == v.size()) v.push_back(cnt);
			else v[idxx] = cnt;
			mp[idxx] = i;
			update(idxx, i);
		}
		return ans == INT_MAX ? -1 : ans;
	}
};

int main()
{
    return 0;
}

