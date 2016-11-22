// uva-127-ֽ��.cpp : �������̨Ӧ�ó������ڵ㡣
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

int top[52];//���ջ��

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
}//�ж��Ƿ����ҵ�ƥ���ƣ�������ƥ���Ƶ�λ��

int main()
{
	char input[2];
    while(1)
	{
		  int i;
		  card pile[52][52];
		  char temp[2];
		  memset(top,0,sizeof(top));//�ǵó�ʼ�����Ǹ���ϰ��
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
			if(top[i]==0)//��i��û����
			{i++;continue;}
	   
			if(!get(x,y,i)){i++;continue;}//��i����߻�����3��û��
	   //printf("###%d/n",i);

	//ƥ��������
		   if(x>=0 && com(pile[i][top[i]-1],pile[x][top[x]-1]))//������������ƥ��
		   {
				pile[x][top[x]].rank=pile[i][top[i]-1].rank;
				pile[x][top[x]].suit=pile[i][top[i]-1].suit;
				top[x]++;
				top[i]--;
				i=x;//�Ӵ˴������������
				continue;//ָ�����
		   }
	  
			x=y;//�鿴��һ��
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

