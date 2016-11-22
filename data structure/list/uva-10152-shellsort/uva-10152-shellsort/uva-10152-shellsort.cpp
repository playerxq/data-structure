// uva-10152-shellsort.cpp : �������̨Ӧ�ó������ڵ㡣
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
int ori[maxn];//��ʼʱ��˳��
int last[maxn];//����ʱ˳��
int pick[maxn] ;
int track[maxn];//���˳�� track[i] Ϊ��ʼʱ��i�Ź굱ǰ���ںδ�
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

// �ѱ��Ϊtrack���ڹ�ŵ���ǰ  
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
			ori[i] = i;//��ʼʱ��i�Ź�ĺ������i
		}
		for(int j = 0;j<num;j++)
		{
			getline(cin,temp);
			last[j] = rak[temp];//����ʱ��˳�� ��i�����ǿ�ʼʱ��ĵڼ�����
		}
		//��ʼʱ�����˳��
		for(int i = 0;i<num;i++)
		{
			track[ori[i]] = i;//��ori[i]�Ź��λ�þ���i
		}
		for(int i = 0;i<num;i++)
		{
			Stack.arr[Stack.top++] = last[i];
		}
		int count = 0;
		Stack.top--;
		while(Stack.top>0)
		{//�Ӻ���ǰȡ
			int a = Stack.arr[Stack.top--];
			int b = Stack.arr[Stack.top];
			if(track[a]<track[b])//��ʼʱλ��Ϊa��Ԫ�����ڴ���λ��b��Ԫ��ǰ�� ������ʱҪ��a��b��
			{
				pick[count++] = b;//b��ȡ���ŵ�ǰ��
				change( ori , track[b] , num ) ;  
                for( int i = 0 ; i < num ; i++ )//�����ı����λ��  
					track[ori[i]] = i ;//���ڵ�λ��
			}
		}
		for( int i = 0 ; i < count ; i++ )  
			cout << original[pick[i]] << endl ;  
        cout << endl ; 
	}
	return 0;
}

