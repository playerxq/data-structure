// uva-133-救济金.cpp : 定义控制台应用程序的入口点。
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

const int maxn = 22;
bool d[maxn];  
int N;
int cw(int pos, int k) {  
    int cnt = 0;  
    for ( ; cnt != k; pos++) {  
        if (pos == N) pos = 0;  
        if (d[pos]) cnt++;  
    }  
    return --pos;  
}  
  
int w(int pos, int m) {  
    int cnt = 0;  
    for (; cnt != m; pos--) {  
        if (pos == -1) pos = N - 1;  
        if (d[pos]) cnt++;  
    }  
    return ++pos;  
}
int main()
{
	int m,k;
	while(scanf("%d%d%d",&N,&k,&m))
	{
		if(N==0&&k==0&&m==0)
			break;
		memset(d, 1, N);
		int tot = N, flag = 0, a = 0, b = N - 1;
		while(tot)
		{
			a = cw(a, k), b = w(b, m);
			tot--;  
            if (flag) printf(",");  
            d[a] = d[b] = false;  
            flag = 1;  
            if (a == b)  
                printf("%3d", a + 1);  
            else {  
                printf("%3d%3d", a + 1, b + 1);  
                tot--;  
			}
		}
		printf("\n");
	}
	return 0;
}

