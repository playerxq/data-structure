// uva-11234-���ʽ.cpp : �������̨Ӧ�ó������ڵ㡣
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

// ���ڴ������ʽ���õ�ջ
tree * Stack[10000];
// �������Ĳ�α����õĶ���
tree * Queue[10000];
int front;
int rear;
int top;

// ������һ��û�к��ӽڵ����
tree * CreatTree(char a) {
	tree * pnode = new tree;
	pnode->rchild = NULL;
	pnode->lchild = NULL;
	pnode->op = a;
	return pnode;
}

// ����������Ϊ���Һ��Ӵ���һ����
tree * CreatTree(char a, tree * pl, tree * pr) {
	tree * pnode = new tree;
	pnode->rchild = pr;
	pnode->lchild = pl;
	pnode->op = a;
	return pnode;
}

// ���Ĳ�α���
void levelOrder(tree * pF, int n) {//��rear�� front��
	char ans[10000];
	int count = 0;
	front = 0; 
	rear = -1;
	// ��ʹ��ȫ�ֱ�����ʱ������ȳ�ʼ��
	// ֮ǰ��Ϊû�г�ʼ����һֱWA������
	// ������û�г�ʼ����ǰ������ݻ�Ӱ�쵱ǰ�����ݡ�
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
			// ���������ans������
			ans[count++] = pnode->op;
		}
	}

	// �����������ans��õ����
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
		levelOrder(Stack[top - 1], len);//���ʽ��ȷʱ��ʱջ��Ӧֻ��rootһ���ڵ�
	}
	return 0;
}


