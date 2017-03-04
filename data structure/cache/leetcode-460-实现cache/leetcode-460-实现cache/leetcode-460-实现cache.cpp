// leetcode-460-实现cache.cpp : 定义控制台应用程序的入口点。
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
#include <unordered_map>
#include <stack>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
class LFUCache {
private:
	int cap;
	int siz;
	int minfreq;
	unordered_map<int, pair<int, int>> m; //key to {value,freq};
	unordered_map<int, list<int>::iterator> mIter; //key to list iterator;
	unordered_map<int, list<int>>  fm;  //freq to key list;
public:
	LFUCache(int capacity) {
		cap = capacity;
		siz = 0;
	}

	int get(int key) {
		if (m.count(key) == 0)
			return -1;
		fm[m[key].second].erase(mIter[key]);
		m[key].second++;
		fm[m[key].second].push_back(key);
		mIter[key] = --fm[m[key].second].end();
		if (fm[minfreq].size() == 0)
			minfreq++;
		return m[key].first;
	}

	void put(int key, int value) {
		if (cap <= 0)
			return;
		int storevalue = get(key);
		if (storevalue != -1)
		{
			m[key].first = value;
			return;
		}
		if (siz >= cap)
		{
			m.erase(fm[minfreq].front());
			mIter.erase(fm[minfreq].front());
			fm[minfreq].pop_front();
			siz--;
		}
		m[key] = {value,1};
		fm[1].push_back(key);
		mIter[key] = --fm[1].end();
		minfreq = 1;
		siz++;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

