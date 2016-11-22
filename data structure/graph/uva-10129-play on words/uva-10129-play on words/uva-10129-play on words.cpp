// uva-10129-play on words.cpp : �������̨Ӧ�ó������ڵ㡣
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
int n;//������
int p_n;//����
char s[1000+10];//�ݴ浥��
char map[100000+10][3];//ÿ������ֻ�迼����β������ĸ
int mp[26][26];
int used[26];//ĳ��ĸ�Ƿ��ǵ�ǰͼ�еĵ�
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
	for(int i = 0;i<26;i++)//ʹ�õ���ĸ����
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
			//ÿ������ֻ�迼����β������ĸ
			gets(s);
			map[i][0]=s[0];
			map[i][1]=s[strlen(s)-1];
		}
		flag = 0;
		int pos;
		//��map�е���ĸ�Թ�������ͼ���ж��Ƿ����ŷ��·��
		construct();
		//���е���ȵ�����Ȼ���ֻ��������ȵ�
		//���Է������ж��Ƿ���ͨ
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
			//�ж϶���
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

