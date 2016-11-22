// uva-839-not so mobile.cpp : 定义控制台应用程序的入口点。
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
int ok;
int dfs()
{
	int w1,d1,w2,d2; 
	scanf("%d%d%d%d",&w1,&d1,&w2,&d2); 
	if ( w1 && d1 && w2 && d2 )  
    {  
        if ( (w1*d1) != (w2*d2) )  
        {  
            ok = 0 ;  
            return 0 ;  
        }  
        else return w1+w2;  
    }
	else
	{
		if ( !w1 )  
            w1 = dfs();
		if ( !w2 )  
            w2 = dfs();
		if ( (w1*d1) != (w2*d2) )  
        {  
            ok = 0 ;  
            return 0;  
        }  
        else return w1+w2; 
	}
}
int main()
{
	int i,N,sum;  
    scanf("%d",&N);  
    for ( i = 1 ; i <= N ; i++)  
    {  
        ok = 1;  
        dfs();  
        if ( ok )  
            printf("YES\n");  
        else printf("NO\n");  
        if ( i != N )  
            printf("\n");  
    }  
    return 0;
}

