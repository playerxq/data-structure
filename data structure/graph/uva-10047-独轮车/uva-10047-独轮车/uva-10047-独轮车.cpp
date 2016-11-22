// uva-10047-独轮车.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include<iomanip>
#include <ctype.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
char map[30][30];
int visit[30][30][4][5];//坐标 方向 颜色 方向0 北 1 东 2 南 3 西 颜色 0 绿 1 白 2 蓝 3 红 4 黑
int sx,sy,ex,ey;
int flag;
int ans;
int r,c;//区域大小
//一个状态的五个属性，坐标，方向，步数  颜色
struct Node { int x ; int y ; int d ; int s ; int c ; } node1 , node2 ;  
//优先队列  
struct cmp  
{  
    bool operator () (const Node a, const Node b)  
    {  
        return a.s > b.s;  
    }  
};  
priority_queue < struct Node ,vector<Node> ,cmp > q ;  

int dir[4] = {0,1,2,3};//北 东南 西
int dir_s[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
bool is_ok( int x , int y , int cc , int d )  
{  
    if(map[x][y] == '#' || visit[x][y][d][cc])  
		return false ;  
    return true ;  
}
int get_step( int nd , int d , int s )  //当前方向与下一个方向反向  步数+2
{  
    if( d == 0 && nd == 2 ) return s + 2 ;  
    else if( d == 1 && nd == 3 ) return s + 2 ;  
    else if( d == 2 && nd == 0 ) return s + 2 ;  
    else if( d == 3 && nd == 1 ) return s + 2 ;  
    else return s + 1 ;  //步数+1
}
bool is_ans( int x , int y , int cc )  
{  
    if( x != ex || y != ey || cc )  
    return false ;  
    return true ;  
} 
void bfs()
{
	node1.x = sx;
	node1.y = sy;
	node1.d = 0;
	node1.c = 0;
	node1.s = 0;
	q.push(node1);
	visit[sx][sy][0][0] = 1;
	int nd;
	while(!q.empty())
	{
		node1 = q.top() ; 
		q.pop() ;  
        int x = node1.x ;  
        int y = node1.y ;  
        int c = node1.c ;  
        int s = node1.s ;  
        int d = node1.d ; 
		for( int i = 0 ; i < 4 ; ++i )
		{
			nd = dir[i];//下个方向
			if(nd!=d)//方向改变
			{
				int ns = get_step( nd , d , s ) ;//方向相对时步数加2
				if( is_ans( x , y , c ) )  
                { ans = ns ; flag = 1 ; return ; }
				if( is_ok( x , y , c , nd ) )  
                {  
                    node2.x = x ;  
                    node2.y = y ;  
                    node2.c = c ;  
                    node2.d = nd ;  
                    node2.s = ns ;  
                    q.push( node2 ) ;  
                    visit[x][y][nd][c] = 1;  
                }
			}
			if( nd == d )//如果方向相同，走一格  
            {  
                int ns = s + 1 ;  
                int nx = x + dir_s[d][0] ;  
                int ny = y + dir_s[d][1] ;  
                int nc = ( c + 1 ) % 5 ;//0 , 1 , 2 , 3 , 4 表示五个颜色  
                if( is_ok( nx , ny , nc , d ) )  
                {  
                    if( is_ans( nx , ny , nc ) )  
                    { ans = ns ; flag = 1 ; return ; }  
                    node2.x = nx ;  
                    node2.y = ny ;  
                    node2.c = nc ;  
                    node2.d = d ;  
                    node2.s = ns ;  
                    q.push( node2 ) ;  
                    visit[nx][ny][d][nc] = 1 ;  
                }  
            }
		}
	}
	return;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int M,N;
	int icase = 1;
	while(scanf("%d%d",&M,&N))
	{
		if(M==0&&N==0)
			break;
		int i,j;
		r = M;
		c = N;
		flag = 0;
		ans = 0;
		while(!q.empty()) q.pop();
		memset(visit,0,sizeof(visit));
		for(i = 1;i<=M;i++)
		{
			getchar();
			for(j = 1;j<=N;j++)
			{
				scanf("%c",&map[i][j]);
				if(map[i][j]=='S')
				{
					sx = i;
					sy = j;
				}
				if(map[i][j]=='T')
				{
					ex = i;
					ey = j;
				}
			}
		}
		for(i = 0;i<N+2;i++)
		{
			map[0][i] = '#';
			map[M+1][i] = '#';
		}
		for(i = 0;i<M+2;i++)
		{
			map[i][0] = '#';
			map[i][N+1] = '#';
		}
		if( icase - 1 ) cout << endl ;  
        bfs() ;  
        if( flag )  
        cout << "Case #" << icase++ << endl << "minimum time = " << ans << " sec" << endl ;  
        else  
        cout << "Case #" << icase++ << endl << "destination not reachable" << endl ; 
	}
	return 0;
}

