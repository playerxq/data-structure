// uva-657-dice.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;
char a[50+5][50+5];
int count;
int i_cmp(void const *x,void const *y)
{
    return *(int*)x-*(int*)y;
}
void DFS_X(int x,int y)
{
    if(a[x][y]!='X')
        return ;
    else
        a[x][y]='.';//找到相邻X就变成.防止重复
    DFS_X(x-1,y);    //题目要求只需要考虑上下左右四个方向即可，而不是八个方向
    DFS_X(x,y-1);
    DFS_X(x,y+1);
    DFS_X(x+1,y);
}
void DFS(int x,int y)
{
    if(a[x][y]=='.')
        return ;
    if(a[x][y]=='X')
    {
        DFS_X(x,y);//开始找相邻X
        count++;
    }
    a[x][y]='.';
    DFS(x-1,y);
    DFS(x,y-1);
    DFS(x,y+1);
    DFS(x+1,y);
}
int main()
{
#ifdef test
    freopen("sample.txt","r",stdin);
#endif
    int w,h,num=1,ct,dote[100];
    while(scanf("%d%d",&w,&h)!=EOF)
    {
        if(w==0&&h==0) break;
        memset(a,'.',sizeof(a));
        for(int i=1; i<=h; i++)
        {
            getchar();
            for(int j=1; j<=w; j++)
                scanf("%c",&a[i][j]);
        }
        ct=0;
        for(int i=1; i<=h; i++)
            for(int j=1; j<=w; j++)
                if(a[i][j]=='*'||a[i][j]=='#')//找到一片区域
                {
                    count=0;
                    DFS(i,j);
                    dote[ct++]=count;
                }
        printf("Throw %d\n",num++);
        qsort(dote,ct,sizeof(dote[0]),i_cmp);
        for(int i=0; i<ct; i++)
            {
                if(i)
                    printf(" ");
                printf("%d",dote[i]);
            }
        printf("\n\n");
    }
    return 0;
}

