// leetcode-588-trie for filesystem.cpp : 定义控制台应用程序的入口点。
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

class FileSystem {
private:
	struct trie
	{
		bool isfile;
		unordered_map<string, trie*> child;
		string content;
		trie() : isfile(false){}
	};
	trie* root;
public:
	FileSystem() {
		root = new trie();
	}
	vector<string> getstr(string& path)
	{
		vector<string> ans;
		int i = 1;
		int j = 1;
		for (; j <= path.length();)
		{
			if (i != j && (j == path.length() || path[j] == '/'))
			{
				ans.push_back(path.substr(i,j-i));
				i = j + 1;
			}
			j++;
		}
		return ans;
	}
	vector<string> ls(string path) {
		vector<string> strs = getstr(path);
		trie* cur = root;
		for (string& str : strs)
		{
			cur = cur->child[str];
		}
		if (cur->isfile)
			return{ strs.back() };
		vector<string> ans;
		for (auto& p : cur->child)
		{
			ans.push_back(p.first);
		}
		sort(ans.begin(),ans.end());
		return ans;
	}

	void mkdir(string path) {
		vector<string> strs = getstr(path);
		trie* cur = root;
		for (string& str : strs)
		{
			if (!cur->child.count(str))
			{
				cur->child[str] = new trie();
			}
			cur = cur->child[str];
		}
	}

	void addContentToFile(string filePath, string content) {
		vector<string> strs = getstr(filePath);
		trie* cur = root;
		for (string& str : strs)
		{
			if (!cur->child.count(str))
			{
				cur->child[str] = new trie();
			}
			cur = cur->child[str];
		}
		cur->isfile = true;
		cur->content += content;
	}

	string readContentFromFile(string filePath) {
		vector<string> strs = getstr(filePath);
		trie* cur = root;
		for (string& str : strs)
		{
			cur = cur->child[str];
		}
		return cur->content;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

