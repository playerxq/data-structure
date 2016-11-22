// uva-327-C expression.cpp : 定义控制台应用程序的入口点。
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
const int maxn = 1000;
char s[maxn];
char s2[maxn];
int s1[maxn];
int a[27];
int used[27];
int i_x;
void init()
{
	memset(s1,0,sizeof(s1));
	memset(s2,0,sizeof(s2));
	memset(a,0,sizeof(a));
	memset(used,0,sizeof(used));
	for(int i = 0;i<27;i++)
	{
		a[i] = i+1;
	}
}
void resize(int i,int flag,int* len)
{
	if(flag==0)//前移
	{
		for(int k = i;k<*len;k++)
		{
			s[k-2] = s[k];
		}
		s[*len-1] = s[*len-2] = 0;
		*len = *len-2;
		return;
	}
	else
	{
		for(int k = i+3;k<*len;k++)
		{
			s[k-2] = s[k];
		}
		s[*len-1] = s[*len-2] = 0;
		*len = *len-2;
		return;
	}
}

void del_space(int* len)
{
	int m = *len;
	for(int i = 0;i<*len;i++)
	{
		if(s[i]==' ')
		{
			for(int j = i+1;j<*len;j++)
			{
				s[j-1] = s[j];
			}
			*len = *len - 1;
		}
	}
	for(int i = *len;i<m;i++)
		s[i] = 0;
}
int caculate(int len)
{
	int res = 0;
	int max_len = len;
	int j = 0;
	for(int i = 0;i<len;i++)
	{
		if(isalpha(s[i])&&s[i+1]=='+'&&s[i+2]=='+')
		{
			s1[j++] = a[s[i]-'a'];
			used[s[i]-'a'] = 1;
			a[s[i]-'a']++;
			resize(i,1,&len);
		}
		else if(isalpha(s[i])&&s[i+1]=='-'&&s[i+2]=='-')
		{
			s1[j++] = a[s[i]-'a'];
			used[s[i]-'a'] = 1;
			a[s[i]-'a']--;
			resize(i,1,&len);
		}
		else if(i>=2&&isalpha(s[i])&&s[i-1]=='+'&&s[i-2]=='+')
		{
			a[s[i]-'a']++;
			used[s[i]-'a'] = 1;
			s1[j++] = a[s[i]-'a'];
			resize(i,0,&len);
			i-=2;
		}
		else if(i>=2&&isalpha(s[i])&&s[i-1]=='-'&&s[i-2]=='-')
		{
			a[s[i]-'a']--;
			used[s[i]-'a'] = 1;
			s1[j++] = a[s[i]-'a'];
			resize(i,0,&len);
			i-=2;
		}
		else if(isalpha(s[i]))
		{
			s1[j++] = a[s[i]-'a'];
			used[s[i]-'a'] = 1;
		}
	}
	for(int i = 0;i<len;i++)
	{
		if(isalpha(s[i]))
		{
			for(int j = i+1;j<len;j++)
			{
				s[j-1] = s[j];
			}
			s[len-1] = 0;
			len--;
		}
	}
	res = s1[0];
	int ind = 0;
	int ix = 1;
	while((ind<len)&&(ix<j))
	{
		switch(s[ind++])
		{
		case '+':
			res+=s1[ix++];
			break;
		case '-':
			res-=s1[ix++];
			break;
		}
	}
	return res;
}
void output(int res)
{
	cout<<"Expression: "<<s2<<endl;
	cout<<"    value = "<<res<<endl;
	for(int i = 0;i<27;i++)
	{
		if(used[i])
			printf("    %c = %d\n",i+'a',a[i]);
	}
}

void copy(int len)
{
	for(int i = 0;i<len;i++)
	{
		s2[i] = s[i];
	}
}
int main()
{
	char ch;
	int ncase = 1;
	while(cin.getline(s,1000))
	{
		init();
		i_x = strlen(s);
		copy(i_x);
		del_space(&i_x);
		int result = caculate(i_x);
		output(result);
	}
	return 0;
}

