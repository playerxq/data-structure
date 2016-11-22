// test-1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<cstring>

using namespace std;

struct node
{
    int data;
    int index;
    node*left,*right;
    node(int a):data(a),index(0),left(0),right(0) {}
};

node* create()
{
    int num;
    cin>>num;
    if(num==-1)
        return 0;
    node*root=new node(num);
    root->left=create();
    root->right=create();
    return root;
}
int arr[10000];
void see(node*root,int index)
{
    if(root)
    {
        //cout<<root->data<<endl;
        arr[index]+=root->data;
        see(root->left,index-1);
        see(root->right,index+1);
    }
}
int main()
{
		freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int cas=0;
    node* root;
    while(root=create())
    {
        memset(arr,0,sizeof(arr));
        int index=100;
        see(root,index);
        while(arr[index])index--;
        cout<<"Case "<<++cas<<":"<<endl;
        for(index++; arr[index]; index++)
        {
            cout<<arr[index];
            if(arr[index+1])cout<<" ";
        }
        cout<<endl<<endl;
    }
    return 0;
}

