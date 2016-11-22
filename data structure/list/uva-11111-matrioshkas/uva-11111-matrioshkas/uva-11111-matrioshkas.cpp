// uva-11111-matrioshkas.cpp : 定义控制台应用程序的入口点。
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
int num[maxn];//套娃的绝对大小
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
				if(a[i]+stack[top]==0)//发生匹配 去掉一个娃
				{
					top--;
					num[top] += abs(a[i]);//当前匹配掉的娃占用了上层娃的容量 num为当前层占用的容量
					if(top&&num[top]>=abs(stack[top]))//当前层已经占用的容量不小于当前层最大娃的容量
					{
						break;
					}
				}
				else
				{
					stack[++top] = a[i];
					num[top] = 0;//当前层一个新娃展开
				}
			}
			if(top)//正负娃没有完全匹配
				printf(":-( Try again.\n");
			else  printf(":-) Matrioshka!\n");
			sum=1;
		}
	}
	return 0;
}

