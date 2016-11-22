// uva-196-spreadsheet.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
const int maxn = 1010;
#define MARK -2147483645
int sheet[maxn][maxn];
string fm[maxn][maxn];
int row,column;//列是26进制
string s;

int dfs(int r,int c){  
    if(sheet[r][c] != MARK) return sheet[r][c];  
    if(sheet[r][c] == MARK){  
        int m_row, m_col;  
        char temp[maxn];   
		string str = fm[r][c];  
  
        sheet[r][c] = 0;  
		int x = str.size();
        for(int i=1, pos=0; i<=str.length(); ++i){  
            if(str[i]=='+' || i==str.length()){  
                temp[pos] = '\0';   
                m_row=0, m_col=0;  
                int k;  
                for(k=0; k<strlen(temp) && !isdigit(temp[k]); ++k){  
                    m_col = m_col*26+temp[k]-'A'+1;  
                    }  
                for( ; k<strlen(temp); ++k){  
                    m_row = m_row*10+temp[k]-'0';   
                }  
                pos = 0;  
                sheet[r][c] += dfs(m_row, m_col);  
            }  
            else{  
                temp[pos++] = str[i];  
            }  
        }  
        return sheet[r][c];  
    }  
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;  
    scanf("%d",&T);  
    while(T--){  
        scanf("%d %d",&column, &row);  
  
        memset(sheet, 0, sizeof(sheet));  
  
        int val;  
        for(int i=1; i<=row; ++i){  
            for(int j=1; j<=column; ++j){  
   
                cin >> s;  
  
                if(s[0]=='='){  
                    sheet[i][j] = MARK;  
                    fm[i][j] = s;  
                }  
                else{  
                    val = atoi(s.c_str());  
                    sheet[i][j] = val;     
                }  
            }  
        }   
        for(int i=1; i<=row; ++i){  
            for(int j=1; j<=column; ++j) if(sheet[i][j]==MARK){  
                dfs(i,j);  
            }  
        }    
  
        for(int i=1; i<=row; ++i){  
            printf("%d",sheet[i][1]);  
            for(int j=2; j<=column; ++j){  
                printf(" %d",sheet[i][j]);  
            }  
            printf("\n");  
        }  
    }  
    return 0;
}

