// uva-10596-����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdio.h>
#define size 210
int num,f,n,visit[size],map[size][size],degree[size];
int dfs(int x)
{
	 int  i;
	 for (i=0;i<n;i++)
		 if ((visit[i]==1)&&(map[x][i]==1))
		 {
			 visit[i]=0; ++num;
			 dfs(i);
		 }
	return 0;
};
int main()
{
	int i,j,r,x,y;
    while (scanf("%d%d",&n,&r)!=EOF)
    {
		  for (i=0;i<n;i++)
		     for (j=0;j<n;j++)
		        map[i][j]=0;
		  for (i=0;i<n;i++)
		  {visit[i]=1; degree[i]=0;}
		  for (i=1;i<=r;i++)
		  {
			  scanf("%d%d",&x,&y);
		      map[x][y]=1;
		      ++degree[x];
		      ++degree[y];
           }
           if (r>0) f=1; else f=0;
           for (i=0;i<n;i++)
              if (degree[i]%2==1) {f=0;break;}
           if (f) {
			   num=1; visit[0]=0; dfs(0); //��ʼд��visit[n-1]��dfs��n-1������������ˣ��ĳ�0�͹��ˣ���ĿҲû˵0����㣬�ж���ͨ�Զ��ѡ������.....
               if (num!=n) f=0;
           }
           if (f) printf("Possible\n");
           else printf("Not Possible\n");
     }
 return 0;
}


