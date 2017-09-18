// leetcode-677-trie.cpp : Defines the entry point for the console application.
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
class MapSum {
public:
	/** Initialize your data structure here. */
	struct trieNode {
		int v = 0;
		bool flag = false;
		trieNode* sons[256];
	};

	trieNode* root;
	MapSum() {
		root = new trieNode();
	}

	void insert(string key, int val) {
		trieNode* r = root;
		for (int i = 0; i<key.size(); i++) {
			if (r->sons[key[i]] == NULL) r->sons[key[i]] = new trieNode();
			r = r->sons[key[i]];
		}
		r->v = val;
		r->flag = true;
	}

	int sum(string prefix) {
		trieNode* r = root;
		for (int i = 0; i<prefix.size(); i++) {
			if (r->sons[prefix[i]] == NULL) return 0;
			r = r->sons[prefix[i]];
		}
		return DFS(r);
	}

	int DFS(trieNode* rt) {
		if (rt == NULL) return 0;
		int res = 0;
		if (rt->flag) res += rt->v;
		for (int i = 0; i<256; i++) {
			if (rt->sons[i] == NULL) continue;
			res += DFS(rt->sons[i]);
		}
		return res;
	}
};

int main()
{
    return 0;
}

