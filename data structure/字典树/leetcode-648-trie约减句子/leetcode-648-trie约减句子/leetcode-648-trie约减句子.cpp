// leetcode-648-trieÔ¼¼õ¾ä×Ó.cpp : Defines the entry point for the console application.
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
class trie
{
public:
	trie* child[26] = {};
	bool isroot= false;
	int insert(string& cur, int ch, int sz)
	{
		if (ch == sz)
			isroot = true;
		if (!isroot)
		{
			if (child[cur[ch] - 'a'] == nullptr)
				child[cur[ch] - 'a'] = new trie();
			child[cur[ch] - 'a']->insert(cur,ch+1,sz);
		}
		return 0;
	}
	int search(string& cur, int st, int ch, int sz)
	{
		if (st + ch == sz || this->isroot == true || cur[st + ch] == ' ')
			return ch;
		if (child[cur[st + ch] - 'a'] == nullptr)
		{
			while (st + ch < sz&&cur[st + ch] != ' ')
				ch++;
			return ch;
		}
		return child[cur[st + ch] - 'a']->search(cur,st,ch+1,sz);
	}
};
class Solution {
public:
	string replaceWords(vector<string>& dict, string sentence) {
		trie t;
		string res;
		for (auto s : dict) t.insert(s, 0, s.size());
		for (int i = 0; i < sentence.size(); )
		{
			if (sentence[i] == ' ') res += sentence[i++];
			auto chars = t.search(sentence, i, 0, sentence.size());
			res += sentence.substr(i, chars);
			for (i += chars; i < sentence.size() && sentence[i] != ' '; ++i);
		}
		return res;
	}
};

int main()
{
    return 0;
}

