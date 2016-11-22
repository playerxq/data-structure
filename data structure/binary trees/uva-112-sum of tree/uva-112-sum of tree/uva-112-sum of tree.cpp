// uva-112-sum of tree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include<iomanip>
#include <ctype.h>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100000;
char ss[maxn];
int prev[maxn];
typedef struct Node
{
	struct Node* left;
	struct Node* right;
	int v;
	Node(int op, struct Node lchild, struct Node rchild){v = op;left = &lchild;right = &rchild;}
	Node(int op){v = op;left = NULL;right = NULL;}
} Node;
vector<char> o;
int i_x;
int get_num()//从i_x开始找一个整数
{
	int sum = 0;
	int flag = 0;
	while(!isdigit(ss[i_x])&&ss[i_x]!='-'){i_x++;}
	if(ss[i_x]=='-') {flag = 1;i_x++;}
	while(isdigit(ss[i_x]))
	{
		sum = sum*10 + ss[i_x] - '0';
		i_x++;
	}
	i_x--;
	if(flag) sum = -sum;
	return sum;
}

Node* makenode(int len)//开始时i_x应为‘(’前一个字符  ss[i_x+1]='('  返回时i_x为')'
{
	i_x++;
	if((ss[i_x]=='(')&&(ss[i_x+1]==')'))
	{
		i_x++;
		//while(i_x<len&&ss[i_x]!='(') i_x++;
		return NULL;
	}
	int op = get_num();
	Node* newnode = new Node(op);
	if(ss[i_x+1]=='(')
	{
		newnode->left = makenode(len);
	}
	if(ss[i_x+1]=='(')
	{
		newnode->right = makenode(len);
	}
	//while((i_x<len)&&(ss[i_x]!='(')) i_x++;
	i_x++;
	return newnode;
}

bool dfs(Node* root, int sum)
{
	Node* p = root;
	int sum_temp = p->v;
	if((p->left==NULL)&&(p->right==NULL)&&(sum_temp==sum))
		return true;
	if(p->left)
	{
		if(dfs(p->left,sum-sum_temp)) return true;
	}
	if(p->right)
	{
		if(dfs(p->right,sum-sum_temp)) return true;
	}
	return false;
}

bool caculate(int sum,int len)
{
	i_x = -1;
	Node* root = makenode(len);
	if(root==NULL)//空树
		return false;
	return dfs(root,sum);
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n;
	char ch;
	while(scanf("%d",&n)!=EOF)
	{
		o.clear();
		memset(ss,0,sizeof(ss));
		ch = 0;
		while(ch!='(')
			scanf("%c",&ch);
		ss[0] = ch;
		o.push_back(ch);
		int i = 1;
		while(o.empty()!=true)
		{
			scanf("%c",&ch);
			if((ch=='(')||(ch==')')||(ch=='-')||(isdigit(ch)))
			{
				if(ch==')')
					o.pop_back();
				else if(ch=='(')
					o.push_back(ch);
				ss[i++] = ch;
			}
		}
		bool flag = false;
		flag = caculate(n,i);
		if(flag)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}

