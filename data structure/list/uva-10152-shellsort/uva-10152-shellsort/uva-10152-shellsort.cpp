// uva-10152-shellsort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <string.h>
#include <string>
#include <math.h>
#include<iomanip>
#include <ctype.h>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
const int maxn = 210;
vector<string> original;
map<string,int> rak;
int ori[maxn];//开始时的顺序
int last[maxn];//结束时顺序
int pick[maxn] ;
int track[maxn];//相对顺序 track[i] 为初始时第i号龟当前处于何处
struct myStack { int top ; int arr[maxn] ; } Stack ;
void init()  
{  
    memset( last , 0 , sizeof( last ) ) ;  
    memset( track , 0 , sizeof( track ) ) ;  
    memset( pick , 0 , sizeof( pick ) ) ;  
    memset( ori , 0 , sizeof( ori ) ) ;  
    memset( Stack.arr , 0 , sizeof( Stack.arr ) ) ;  
    Stack.top = 0 ;  
    original.clear() ;  
    return ;  
} 

// 把编号为track的乌龟放到最前  
void change( int a[] , int track , int n )  
{  
    int tem[maxn] ;  
    memset( tem , 0 , sizeof( tem ) ) ;  
    int count = 0 ;  
    tem[count++] = a[track] ;  
    for( int i = 0 ; i < n ; i++ )  
    if( i != track ) tem[count++] = a[i] ;  
    for( int i = 0 ; i < count ; i++ )  
    a[i] = tem[i] ;  
    return ;  
} 
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		init() ;
		int num = 0;
		cin>>num;
		string temp;
		getchar();
		for(int i = 0;i<num;i++)
		{
			getline(cin,temp);
			original.push_back(temp);
			rak[temp] = i;
			ori[i] = i;//开始时第i号龟的号码就是i
		}
		for(int j = 0;j<num;j++)
		{
			getline(cin,temp);
			last[j] = rak[temp];//结束时的顺序 第i个龟是开始时候的第几个龟
		}
		//初始时的相对顺序
		for(int i = 0;i<num;i++)
		{
			track[ori[i]] = i;//第ori[i]号龟的位置就是i
		}
		for(int i = 0;i<num;i++)
		{
			Stack.arr[Stack.top++] = last[i];
		}
		int count = 0;
		Stack.top--;
		while(Stack.top>0)
		{//从后向前取
			int a = Stack.arr[Stack.top--];
			int b = Stack.arr[Stack.top];
			if(track[a]<track[b])//开始时位置为a的元素现在处于位置b的元素前面 而结束时要求a在b后
			{
				pick[count++] = b;//b号取出放到前面
				change( ori , track[b] , num ) ;  
                for( int i = 0 ; i < num ; i++ )//改完后改变相对位置  
					track[ori[i]] = i ;//现在的位置
			}
		}
		for( int i = 0 ; i < count ; i++ )  
			cout << original[pick[i]] << endl ;  
        cout << endl ; 
	}
	return 0;
}

