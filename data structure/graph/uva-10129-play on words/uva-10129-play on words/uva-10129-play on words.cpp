// uva-10129-play on words.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
int n;//单词数
int p_n;//点数
char s[1000+10];//暂存单词
char map[100000+10][3];//每个单词只需考虑首尾两个字母
int mp[26][26];
int used[26];//某字母是否是当前图中的点
int vis[26];
int flag;
int indegree[26];
int outdegree[26];


void construct()
{
	p_n = 0;
	memset(mp,0,sizeof(mp));
	memset(used,0,sizeof(used));
	memset(vis,0,sizeof(vis));
	memset(indegree,0,sizeof(indegree));
	memset(outdegree,0,sizeof(outdegree));
	for(int i = 0;i<n;i++)
	{
		mp[map[i][0]-'a'][map[i][1]-'a'] = 1;
		indegree[map[i][1]-'a']++;
		outdegree[map[i][0]-'a']++;
		used[map[i][0]-'a'] = 1;
		used[map[i][1]-'a'] = 1;
	}
	for(int i = 0;i<26;i++)//使用的字母保存
		if(used[i])
			p_n++;
}
int len;
int dfs(int start)
{
    int i;  
    vis[start] = true;  
	len++;
	if (len == p_n)  
        return true;  
    for (i = 0; i < 26; i++)  
    {  
        if (mp[start][i] && !vis[i])  
        {  
            if (dfs(i))  
                return true;  
        }  
    }
    return false; 
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		memset(map,0,sizeof(map));
		memset(s,0,sizeof(s));
		getchar();
		for(int i = 0;i<n;i++)
		{
			//每个单词只需考虑首尾两个字母
			gets(s);
			map[i][0]=s[0];
			map[i][1]=s[strlen(s)-1];
		}
		flag = 0;
		int pos;
		//用map中的字母对构建有向图，判断是否存在欧拉路径
		construct();
		//所有点出度等于入度或者只有两个奇度点
		//忽略方向性判断是否连通
		for(int i = 0;i<26;i++)
		{
			if (indegree[i] != 0 || outdegree[i] != 0)  
			{
				pos = i;
                break;
			}
		}
		len = 0;
		flag = dfs(pos);
		if(!flag)
		{
			cout << "The door cannot be opened." << endl;  
            continue;
		}
		else
		{
			int nSpecial = 0;
			//判断度数
			for(int i = 0;i<26;i++)
			{
				if(indegree[i]||outdegree[i])
				{
					if (indegree[i] - outdegree[i] == 1 || outdegree[i] - indegree[i] == 1)  
						nSpecial++;  
					else  
					{  
						if (indegree[i] != outdegree[i])  
						{  
							nSpecial = -1;  
							break;  
						}  
					}
				}
			}
			if(nSpecial ==0 || nSpecial == 2)  
				cout << "Ordering is possible." << endl;  
			else  
				cout << "The door cannot be opened." << endl;
		}
	}
	return 0;
}

