// leetcode-855-exam.cpp : Defines the entry point for the console application.
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
class Int
{
public:
	int st;
	int ed;
	int mid;
	int dis;
	Int(int a, int b, int n)
	{
		set(a,b,n);
	}
	void set(int a, int b, int n)
	{
		st = a;
		ed = b;
		if (a == INT_MIN)
		{
			mid = 0;
			if (b == INT_MAX)
			{
				dis = 0;
				return;
			}
			dis = b;
			return;
		}
		if (b == INT_MAX)
		{
			dis = n-1 - a;
			mid = n - 1;
			return;
		}
		mid = (a + b) >> 1;
		dis = min(mid - a, b - mid);
		return;
	}
};
struct cmp
{
	bool operator()(const Int& a, const Int& b) const
	{
		if (a.dis != b.dis)
			return a.dis > b.dis;
		if (a.mid != b.mid)
			return a.mid < b.mid;
		return (a.st == b.st) ? (a.ed < b.ed) : (a.st < b.st);
	}
};
class ExamRoom {
public:
	int n;
	set<Int, cmp> s;
	unordered_map<int, pair<set<Int, cmp>::iterator, set<Int, cmp>::iterator>> mp;
	ExamRoom(int N) {
		n = N;
		s.insert(Int(INT_MIN,INT_MAX,n));
	}

	int seat() {
		auto it = s.begin();
		auto it1 = s.insert(Int(it->st,it->mid,n));
		auto it2 = s.insert(Int(it->mid,it->ed,n));
		auto pos = it->mid;
		mp[pos] = make_pair(it1.first,it2.first);
		mp[it->st].second = it1.first;
		mp[it->ed].first = it2.first;
		s.erase(it);
		return pos;
	}

	void leave(int p) {
		int st = mp[p].first->st;
		int ed = mp[p].second->ed;
		s.erase(mp[p].first);
		s.erase(mp[p].second);
		auto it = s.insert(Int(st,ed,n));
		mp.erase(p);
		mp[st].second = it.first;
		mp[ed].first = it.first;
	}
};

int main()
{
    return 0;
}

