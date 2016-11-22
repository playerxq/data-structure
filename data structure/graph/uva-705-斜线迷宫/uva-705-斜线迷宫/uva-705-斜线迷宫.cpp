/*
��\����ʾΪ1 0 0  ��/����ʾΪ0 0 1

				0 1 0              0 1 0

				0 0 1              1 0 0
				ֻ�迼�����������ĸ�����
*/

#include "stdafx.h"
#include<iostream>
#include<cstring>
using namespace std;

int w,h,circles,maxroad,map[250][250];
int dr[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};
bool ok=1,visit[250][250];

void fill(int type,int row,int column){
	if (type==1){
		map[row][column]=1;map[row][column+1]=0;map[row][column+2]=0;
		map[row+1][column]=0;map[row+1][column+1]=1;map[row+1][column+2]=0;
		map[row+2][column]=0;map[row+2][column+1]=0;map[row+2][column+2]=1;
	}
	else{
		map[row][column]=0;map[row][column+1]=0;map[row][column+2]=1;
		map[row+1][column]=0;map[row+1][column+1]=1;map[row+1][column+2]=0;
		map[row+2][column]=1;map[row+2][column+1]=0;map[row+2][column+2]=0;
	}
}
//·��Ҫô��· Ҫôͨ������  ���߲������н���  ��ֻҪ�ҵ�һ��ͨ������ĵ�  ��ǰ·������
//����û�зֲ�  ��ֻ����һ��������չ���ջص���� stepֻ�ᳯһ��������� 
int dfs(int row,int column,int &steps){
	int nr,nc;
	for (int i=0;i<4;i++){
		nr=row+dr[i];
		nc=column+dc[i];
		if (nr<0||nr>=3*h||nc<0||nc>=3*w||visit[nr][nc]==-1) {
			ok=0;
			visit[row][column]=-1;//��·ͨ���Թ�����
		}
		else if (visit[nr][nc]==0&&map[nr][nc]==0) {
			visit[nr][nc]=1;
			steps++;
			dfs(nr,nc,steps);
		}
	}
	return steps;
}
void init()
{
	circles=0;
	maxroad=0;
	ok=1;
	memset(visit,0,sizeof(visit));
}
int main(){
	int col=0;
	while(cin>>w>>h&&w)
	{
		init();
		col++;
		for (int i=0;i<h;i++)
		{
			for (int j=0;j<w;j++){
				char c;cin>>c;
				if (c=='\\') fill(1,3*i,3*j);
				else if (c=='/') fill(2,3*i,3*j);
				else cout<<"wrong input!"<<endl;

			}
		}
		for (int i=0;i<3*h;i++){
			for (int j=0;j<3*w;j++){
				int count=1;
				if(visit[i][j]==0&&map[i][j]==0) 
					{
						ok=1;
						visit[i][j]=1;
						dfs(i,j,count);
						if (ok) 
						{
							circles++;
							if (count>maxroad) maxroad=count;
						}
					}
			}
		}
		cout<<"Maze #"<<col<<":"<<endl;
		if (circles>0)	cout<<circles<<" Cycles; the longest has length "<<maxroad/3<<"."<<endl<<endl;
		else cout<<"There are no cycles."<<endl<<endl;
		
	}
	return 0;
}