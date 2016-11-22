// uva-673-parenthese balance.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include<iomanip>
#include <ctype.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<char> s;
bool ok(int len)
{
	if(((s[len-1]==')')&&(s[len-2]=='('))||((s[len-1]==']')&&(s[len-2]=='[')))
		return 1;
	return 0;
}
int main()
{
	int n;
	cin>>n;
	getchar();
	while(n--)
	{
		
		string temp;
		s.clear();
		getline(cin,temp);
		
		for(int i = 0;i<temp.length();i++)
		{
			s.push_back(temp[i]);
			int len = s.size();
			if(len>1&&ok(len))
			{
				s.pop_back();
				s.pop_back();
			}
		}
		if(s.empty())
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}

