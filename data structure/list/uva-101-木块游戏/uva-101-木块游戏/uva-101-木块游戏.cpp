// uva-101-ľ����Ϸ.cpp : �������̨Ӧ�ó������ڵ㡣
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
	//��a��λ��
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
			tempStk.push(temp);//��a����Ķ��ŵ�tempջ��
		}
		while (!tempStk.empty())//��ԭ��˳��Ż�
		{
			temp = tempStk.top();
			stk[i].push(temp);
			tempStk.pop();
		}
		if (flag)//�ҵ�a
			break;
	}
	//��b��λ��
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
				stk[posb].pop();//��b����Ŀ�ȡ��  �ŵ����ʼλ����
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
			temp = stk[posa].top();//��a�ŵ�b��
			stk[posa].pop();
			stk[posb].push(temp);
		}
		else//ֻ��a�ϵķŵ���ʼλ����
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
	else //��һ���ŵ���һ����
	{
		if (act2 == "onto")
		{
			//���b�ϵ�ľ��
			while (1)
			{
				temp = stk[posb].top();
				if (temp == b)
					break;
				stk[posb].pop();
				stk[temp].push(temp);
			}
			while (1)//��a�ϵ�ľ��ŵ�tempջ��
			{
				temp = stk[posa].top();
				if (temp == a)
					break;
				stk[posa].pop();
				tempStk.push(temp);
			}
			temp = stk[posa].top();//��a�ŵ�b��
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
	//��ʼ״̬
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


