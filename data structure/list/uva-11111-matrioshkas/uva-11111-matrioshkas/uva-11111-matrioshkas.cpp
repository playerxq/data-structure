// uva-11111-matrioshkas.cpp : �������̨Ӧ�ó������ڵ㡣
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
const int maxn = 30000;
int a[maxn];
int stack[maxn];
int num[maxn];//���޵ľ��Դ�С
int main()
{
	char ch;
	int sum = 1;
	int top;
	while(scanf("%d%c",&a[sum],&ch)!=EOF)
	{
		if(ch==' ')
		{
			sum++;
		}
		else
		{
			top = 1;
			stack[top] = a[1];
			num[1] = 0;
			for(int i = 2;i<=sum;i++)
			{
				if(top&&a[i]>0&&stack[top]+a[i]!=0)
				{
					break;
				}
				if(a[i]+stack[top]==0)//����ƥ�� ȥ��һ����
				{
					top--;
					num[top] += abs(a[i]);//��ǰƥ�������ռ�����ϲ��޵����� numΪ��ǰ��ռ�õ�����
					if(top&&num[top]>=abs(stack[top]))//��ǰ���Ѿ�ռ�õ�������С�ڵ�ǰ������޵�����
					{
						break;
					}
				}
				else
				{
					stack[++top] = a[i];
					num[top] = 0;//��ǰ��һ������չ��
				}
			}
			if(top)//������û����ȫƥ��
				printf(":-( Try again.\n");
			else  printf(":-) Matrioshka!\n");
			sum=1;
		}
	}
	return 0;
}

