#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
#include <queue> 
using namespace std; 
struct node 
{ 
     long num; 
     int next[26]; 
     void init(){memset(next,-1,sizeof(next));num=0;} 
}s[3000000]; 

int p; 
char a[100]; 

inline void preprocess(){s[p=0].init();} 

inline void insert() 
{ 
    int index=0; //0´ú±í¸ù
    ++s[index].num; 
    for(int i=0;a[i]!='\0';i++) 
    { 
       int x=a[i]-'a'; 
       if(s[index].next[x]==-1) 
       { 
          s[++p].init(); 
          s[index].next[x]=p; 
       } 
       index=s[index].next[x]; 
       s[index].num++; 
    } 
} 

inline long ct() 
{ 
    long index=0; 
    long i; 

    for (i=0;a[i]!='\0';++i) 
    { 
       long x=a[i]-'a'; 
       if (s[index].next[x]==-1) return 0; 
       index=s[index].next[x]; 
    } 

    return s[index].num; 
} 


int main() 
{ 
    preprocess(); 

    while (gets(a)) 
    { 

       if(a[0]=='\0') 
       { 
          break; 
       }  

       insert(); 
    } 

    while(gets(a)) 
    {   
        printf("%ld\n",ct()); 
    } 

    return 0; 
}