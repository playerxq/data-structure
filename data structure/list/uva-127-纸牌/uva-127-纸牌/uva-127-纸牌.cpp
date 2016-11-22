// uva-127-纸牌.cpp : 定义控制台应用程序的入口点。
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

typedef struct card
{
	 char rank;
	 char suit;
}card;

int top[52];//标记栈顶

bool com(card a,card b)
{
	 if(a.rank==b.rank || a.suit==b.suit)return 1;
	 else return 0;
}
int get(int &x,int &y,int pos)
{
	 int i,prep=1,flag=1,num=0;
	 x=-1;y=-1;
	 for(i=pos-1;i>=0;i--)
	 {
		if(top[i]>0) num++;
		if(num==1 && prep) {y=i;prep=0;}
	 
		if(num==3 ) {x=i;break;}
	  //if(num>3) break;
	 }
	 if(x>=0 || y>=0)
		return 1;
	 return 0;
}//判断是否能找到匹配牌，并返回匹配牌的位置

int main()
{
	char input[2];
    while(1)
	{
		  int i;
		  card pile[52][52];
		  char temp[2];
		  memset(top,0,sizeof(top));//记得初始化，是个好习惯
		  scanf("%s",temp);
		  if(temp[0]=='#') return 0;
		  pile[0][top[0]].rank=temp[0];
		  pile[0][top[0]++].suit=temp[1];
		  for(i=1;i<52;i++)
		  {
			scanf("%s",temp);
			pile[i][top[i]].rank=temp[0];
			pile[i][top[i]++].suit=temp[1];
		  }
		 for(i=1;i<52;)
		{
			int x=-1,y=-1;
			if(top[i]==0)//第i堆没有牌
			{i++;continue;}
	   
			if(!get(x,y,i)){i++;continue;}//第i堆左边或者左3格没牌
	   //printf("###%d/n",i);

	//匹配与重组
		   if(x>=0 && com(pile[i][top[i]-1],pile[x][top[x]-1]))//左三格有牌且匹配
		   {
				pile[x][top[x]].rank=pile[i][top[i]-1].rank;
				pile[x][top[x]].suit=pile[i][top[i]-1].suit;
				top[x]++;
				top[i]--;
				i=x;//从此处继续向左查找
				continue;//指针回溯
		   }
	  
			x=y;//查看左一格
			if(x>=0 && com(pile[i][top[i]-1],pile[x][top[x]-1]))
			{
				pile[x][top[x]].rank=pile[i][top[i]-1].rank;
				pile[x][top[x]].suit=pile[i][top[i]-1].suit;
				top[x]++;
				top[i]--;
				i=x;
				continue;
			}
			i++;
		}
		  int total=0;
		  for(i=0;i<52;i++)
			if(top[i]>0)total++;
		if(total==1) printf("1 pile remaining: 52");
		else
		{
		   printf("%d piles remaining:",total);
		   for(i=0;i<52;i++)
				if(top[i]>0){ printf(" %d",top[i]);}
		}
		printf("\n");
	}
	return 0;
}

