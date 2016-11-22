// uva-101-木块游戏.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

////
const int MAX_S = 30;


stack<int> stk[MAX_S];
stack<int> tempStk;
int N;
int posa, posb;

void action(const string act1, const string act2, int a, int b)
{
	int i, j;
	int temp;
	if (act1 == act2)
		return;
	bool flag = false;
	//找a的位置
	for (i = 0; i < N; i++)
	{
		while (!stk[i].empty())
		{
			temp = stk[i].top();
			if (temp == a)
			{
				posa = i;
				flag = true;
				break;
			}
			stk[i].pop();
			tempStk.push(temp);//将a上面的都放到temp栈中
		}
		while (!tempStk.empty())//按原来顺序放回
		{
			temp = tempStk.top();
			stk[i].push(temp);
			tempStk.pop();
		}
		if (flag)//找到a
			break;
	}
	//找b的位置
	flag = false;
	for (i = 0; i < N; i++)
	{
		while (!stk[i].empty())
		{
			temp = stk[i].top();
			if (temp == b)
			{
				posb = i;
				flag = true;
				break;
			}
			stk[i].pop();
			tempStk.push(temp);
		}
		while (!tempStk.empty())
		{
			temp = tempStk.top();
			stk[i].push(temp);
			tempStk.pop();
		}
		if (flag)
			break;
	}
	if (posa == posb)
		return;
	////
	if (act1 == "move")
	{
		if (act2 == "onto")//
		{
			while (1)
			{
				temp = stk[posb].top();
				if (temp == b)
					break;
				stk[posb].pop();//将b上面的块取出  放到其初始位置上
				stk[temp].push(temp);
			}
			while (1)
			{
				temp = stk[posa].top();
				if (temp == a)
					break;
				stk[posa].pop();
				stk[temp].push(temp);
			}
			temp = stk[posa].top();//将a放到b上
			stk[posa].pop();
			stk[posb].push(temp);
		}
		else//只将a上的放到初始位置上
		{
			while (1)
			{
				temp = stk[posa].top();
				if (temp == a)
					break;
				stk[posa].pop();
				stk[temp].push(temp);
			}
			temp = stk[posa].top();
			stk[posa].pop();
			stk[posb].push(temp);
		}
		

	}
	else //将一摞放到另一摞上
	{
		if (act2 == "onto")
		{
			//清空b上的木块
			while (1)
			{
				temp = stk[posb].top();
				if (temp == b)
					break;
				stk[posb].pop();
				stk[temp].push(temp);
			}
			while (1)//将a上的木块放到temp栈中
			{
				temp = stk[posa].top();
				if (temp == a)
					break;
				stk[posa].pop();
				tempStk.push(temp);
			}
			temp = stk[posa].top();//将a放到b上
			stk[posa].pop();
			tempStk.push(temp);
			while (!tempStk.empty())
			{
				temp = tempStk.top();
				stk[posb].push(temp);
				tempStk.pop();
			}
		}
		else
		{
			while (1)
			{
				temp = stk[posa].top();
				if (temp == a)
					break;
				stk[posa].pop();
				tempStk.push(temp);
			}
			temp = stk[posa].top();
			stk[posa].pop();
			tempStk.push(temp);
			while (!tempStk.empty())
			{
				temp = tempStk.top();
				stk[posb].push(temp);
				tempStk.pop();
			}
			
		}
	}
}

int main()
{

	///
	int i, j;
	int temp;
	string act1, act2;
	int a, b;
	stack<int> tempStk;

	cin >> N;
	//初始状态
	for (i = 0; i < N; i++)
		stk[i].push(i);
		
	while (1)
	{
		cin >> act1;
		if (act1 == "quit")
			break;
		cin >> a >> act2 >> b;
		action(act1, act2, a, b);

	}
	for (i = 0; i < N; i++)
	{
		printf("%d:", i);
		while (!stk[i].empty())
		{
			temp = stk[i].top();
			stk[i].pop();
			tempStk.push(temp);	
		}
		if (!tempStk.empty())
			printf(" ");
		while (!tempStk.empty())
		{
			temp = tempStk.top();
			printf("%d",temp);
			tempStk.pop();
			if (tempStk.empty())
				break;
			printf(" ");
		}
		printf("\n");
	}

	///
	return 0;
}


