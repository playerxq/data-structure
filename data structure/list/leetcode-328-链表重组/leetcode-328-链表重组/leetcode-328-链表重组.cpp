// leetcode-328-链表重组.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		ListNode* cur = head;
		ListNode* nx = head;
		ListNode* pre = head;
		ListNode* pre_n = head;
		if (head == NULL)
			return head;
		int cnt = 0;
		ListNode* sec = head->next;
		while (cur != NULL)
		{
			nx = cur->next;
			pre = nx;
			if (nx != NULL)
			{
				nx = nx->next;
				cur->next = nx;
			}
			cnt++;
			if (cnt % 2 == 1)
				pre_n = cur;
			cur = pre;
		}
		pre_n->next = sec;
		return head;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

