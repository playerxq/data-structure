// leetcode-160-查找链表交点.cpp : 定义控制台应用程序的入口点。
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL||headB==NULL)
			return NULL;
		ListNode* tail = headB;
		while(tail!=NULL&&tail->next!=NULL)
		{
			tail = tail->next;
		}
		tail->next = headB;
		ListNode* slow,*fast;
		slow = fast = headA;
		int flag = 0;
		while(fast!=NULL&&fast->next!=NULL&&fast->next->next!=NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
			if(slow==fast)
			{
				flag = 1;
				break;
			}
		}
		if(!flag)
		{
			tail->next = NULL;
			return NULL;
		}
		slow = headA;
		while(slow!=fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
		tail->next = NULL;
		return slow;
    }
};
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
}

