// uva-442-矩阵乘法.cpp : 定义控制台应用程序的入口点。
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
typedef struct Marix
{
	char name;
	int row;
	int column;
	Marix(char c,int r,int cl){row = r;column = cl;name = c;}
	Marix(){row = 0;column = 0;name = 0;}
	Marix& operator = (const Marix m)
	{
		row = m.row;
		column = m.column;
		name = m.name;
		return *this;
	}
} Marix;
Marix marix[27];
vector<Marix> v;
int count_n;
bool ok(char a, Marix* b)//b*a
{
	if((*b).column==marix[a-'A'].row)
	{
		count_n += (*b).row*(*b).column*marix[a-'A'].column;
		(*b).column = marix[a-'A'].column;
		return 1;
	}
	return 0;
}
bool ok_marix(Marix* a, Marix b)//a*b
{
	if((*a).column==b.row)
	{
		count_n += (*a).row*(*a).column*b.column;
		(*a).column = b.column;
		return 1;
	}
	return 0;
}
int main()
{
	int n;
	cin>>n;
	int row = 0;
	int column = 0;
	char name;
	memset(marix,0,sizeof(marix));
	for(int i = 0;i<n;i++)
	{
		getchar();
		scanf("%c %d %d",&name,&row,&column);
		marix[name-'A'].row = row;
		marix[name-'A'].column = column;
	}
	getchar();
	string temp;
	v.clear();
	while(getline(cin,temp))
	{
		int len = temp.length();
		v.clear();
		count_n = 0;
		int flag = 1;
		for(int i = 0;i<len;i++)
		{
			if(temp[i]=='(')
			{
				Marix t('(',0,0);
				v.push_back(t);
			}
			else if(temp[i]==')')
			{
				int len_v = v.size();
				Marix m = v[len_v-1];
				v.pop_back();
				v.pop_back();
				len_v = v.size();
				if(len_v==0)
					break;
				if(v[len_v-1].name!='(')
				{
					Marix x = v[len_v-1];
					v.pop_back();
					if(ok_marix(&x,m))
					{
						v.push_back(x);
					}
					else
					{
						flag = 0;
						break;
					}
				}
				else
				{
					v.push_back(m);
				}
			}
			else
			{
				int len_v = v.size();
				if((len_v>0)&&(v[len_v-1].name!='('))
				{
					Marix m = v[len_v-1];
					v.pop_back();
					if(ok(temp[i],&m))//m*temp[i]
					{
						v.push_back(m);
					}
					else
					{
						flag = 0;
						break;
					}
				}
				else
				{
					Marix m(temp[i],marix[temp[i]-'A'].row,marix[temp[i]-'A'].column);
					v.push_back(m);
				}
			}
		}
		if(!flag)
			cout<<"error"<<endl;
		else
			cout<<count_n<<endl;
	}
	return 0;
}

