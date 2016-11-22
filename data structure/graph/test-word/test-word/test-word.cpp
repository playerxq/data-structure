// test-word.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<cstdio>
#include<cstring>
#include<memory>
#include<queue>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

///
#define Maxn 26
bool maze[Maxn][Maxn];
int inEdges[Maxn];
int outEdges[Maxn];
bool vis[Maxn];
int nWords;
int nLetters;
bool dfs(int start, int total)
{
	if (total == nLetters)
		return true;
	int i;
	vis[start] = true;
	for (i = 0; i < Maxn; i++)
	{
		if (maze[start][i] && !vis[i])
		{
			if (dfs(i, total + 1))
				return true;
		}
	}
	return false;
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	///
	int i, j;
	int nCases;
	cin >> nCases;
	while (nCases--)
	{
		nLetters = 0;
		memset(maze, 0, sizeof(maze));
		memset(inEdges, 0, sizeof(inEdges));
		memset(outEdges, 0, sizeof(outEdges));
		memset(vis, 0, sizeof(vis));
		cin >> nWords;
		for (i = 0; i < nWords; i++)
		{
			char sLetter, eLetter, buffer[1010];
			cin >> buffer;
			sLetter = buffer[0] - 'a';
			eLetter = buffer[strlen(buffer) - 1] - 'a';
			maze[sLetter][eLetter] = true;
			inEdges[eLetter]++;
			outEdges[sLetter]++;
			if (!vis[sLetter])
			{
				vis[sLetter] = true;
				nLetters++;
			}
			if (!vis[eLetter])
			{
				vis[eLetter] = true;
				nLetters++;
			}
		}
		memset(vis, 0, sizeof(vis));
		int pos = 0;
		for (pos = 0; pos < Maxn; pos++)
		{
			if (inEdges[pos] != 0 || outEdges[pos] != 0)
				break;
		}
		if (!dfs(pos, 1))
		{
			cout << "The door cannot be opened." << endl;
			continue;
		}

		int nSpecial = 0;
		for (i = 0; i < Maxn; i++)
		{
			if (inEdges[i] != 0 || outEdges != 0)
			{
				if (inEdges[i] - outEdges[i] == 1 || outEdges[i] - inEdges[i] == 1)
					nSpecial++;
				else
				{
					if (inEdges[i] != outEdges[i])
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

	



	///
    return 0;
}

