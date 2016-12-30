// leetcode-211-搜索字符串.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
class TreeNode
{
public:
	bool ed;
	TreeNode* nx[26];
	TreeNode()
	{
		ed = false;
		for(int i = 0;i<26;i++)
		{
			nx[i] = NULL;
		}
	}
};
class WordDictionary {
public:
	TreeNode* root;
	WordDictionary() {
        root = new TreeNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        int len = word.length();
		TreeNode* cur = root;
		for(int i = 0;i<len;i++)
		{
			if(cur->nx[word[i]-'a']==NULL)
			{
				cur->nx[word[i]-'a'] = new TreeNode();
			}
			cur = cur->nx[word[i]-'a'];
		}
		cur->ed = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
	bool search_non(string word, TreeNode* cur)
	{
		if(word=="")
			return cur->ed==true;
		if(word[0]!='.')
		{
			if(cur->nx[word[0]-'a']==NULL)
				return false;
			else
				return search_non(word.substr(1),cur->nx[word[0]-'a']);
		}
		else
		{
			bool ret = false;
			for(int i = 0;i<26;i++)
			{
				if(cur->nx[i]!=NULL)
				{
					ret = search_non(word.substr(1),cur->nx[i]);
					if(ret)
						return true;
				}
			}
			return false;
		}
	}
    bool search(string word) {
        int len = word.length();
		TreeNode* cur = root;
		return search_non(word,cur);
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

