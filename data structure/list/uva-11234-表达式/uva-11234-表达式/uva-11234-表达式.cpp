// uva-11234-表达式.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

struct tree
{
	tree* rchild;
	tree* lchild;
	char op;
};

// 用于创建表达式树用的栈
tree * Stack[10000];
// 用于树的层次遍历用的队列
tree * Queue[10000];
int front;
int rear;
int top;

// 创建了一颗没有孩子节点的树
tree * CreatTree(char a) {
	tree * pnode = new tree;
	pnode->rchild = NULL;
	pnode->lchild = NULL;
	pnode->op = a;
	return pnode;
}

// 由两颗树作为左右孩子创建一颗树
tree * CreatTree(char a, tree * pl, tree * pr) {
	tree * pnode = new tree;
	pnode->rchild = pr;
	pnode->lchild = pl;
	pnode->op = a;
	return pnode;
}

// 树的层次遍历
void levelOrder(tree * pF, int n) {//从rear出 front入
	char ans[10000];
	int count = 0;
	front = 0; 
	rear = -1;
	// 在使用全局变量的时候最好先初始化
	// 之前因为没有初始化而一直WA，后来
	// 发现是没有初始化，前面的数据会影响当前的数据。
	memset(Queue, 0, sizeof(Queue));
	Queue[front++] = pF;
	
	while (rear < front) {
		tree * pnode = Queue[++rear];
		if (pnode != NULL) {
			if (pnode->lchild != NULL) {
				Queue[front++] = pnode->lchild;
			} 
			if (pnode->rchild != NULL) {
				Queue[front++] = pnode->rchild;
			}
			// 结果保存在ans数组中
			ans[count++] = pnode->op;
		}
	}

	// 逆序输出数组ans便得到结果
	for (int i = count - 1; i >= 0; i--) {
		cout << ans[i];
	}
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	while (n--) 
	{
		string str;
		cin >> str;
		int i;
		int len = str.size();
		top = 0;
		for (i = 0; i < len; i++) 
		{
			if (islower(str[i])) {
				tree * ptree = CreatTree(str[i]);
				Stack[top++] = ptree;
			} else {
				tree * prtree = Stack[--top];
				tree * pltree = Stack[--top];
				tree * pF = CreatTree(str[i], pltree, prtree);
				Stack[top++] = pF;
			}
		}
		levelOrder(Stack[top - 1], len);//表达式正确时此时栈内应只有root一个节点
	}
	return 0;
}


