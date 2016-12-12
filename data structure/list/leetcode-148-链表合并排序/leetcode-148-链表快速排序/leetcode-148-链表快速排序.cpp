// leetcode-148-链表快速排序.cpp : 定义控制台应用程序的入口点。
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
	ListNode* combine(ListNode* f1, ListNode* f2)
	{
		ListNode* p1 = f1;
		ListNode* p2 = f2;
		ListNode* res = NULL;
		ListNode* head_p = NULL;
		while(p1!=NULL&&p2!=NULL)
		{
			if(res==NULL)
			{
				if(p1->val<=p2->val)
				{
					res = p1;
					p1 = p1->next;
				}
				else
				{
					res = p2;
					p2 = p2->next;
				}
				head_p = res;
			}
			else
			{
				if(p1->val<=p2->val)
				{
					res->next = p1;
					p1 = p1->next;
				}
				else
				{
					res->next = p2;
					p2 = p2->next;
				}
				res = res->next;
			}
		}
		if(p1!=NULL)
			res->next = p1;
		else if(p2!=NULL)
			res->next = p2;
		return head_p;
	}
	ListNode* mergesort(ListNode* head, ListNode* tail)
	{
		if(head==tail)
			return head;
		ListNode* slow = head;
		ListNode* fast = head;
		ListNode* head_p = NULL;
		while(fast!=tail&&fast->next!=tail)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		ListNode* tt = slow->next;
		slow->next = NULL;
		tail->next = NULL;
		ListNode* r1 = mergesort(head,slow);
		ListNode* r2 = mergesort(tt,tail);
		head_p = combine(r1,r2);
		return head_p;
	}
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL)
			return head;
		ListNode* slow = head;
		ListNode* fast = head;
		while(fast!=NULL&&fast->next!=NULL&&fast->next->next!=NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
		}
		ListNode* tail = head;
		while(tail!=NULL&&tail->next!=NULL)
			tail = tail->next;
		ListNode* tt = slow->next;
		slow->next = NULL;
		tail->next = NULL;
		ListNode* r1 = mergesort(head,slow);
		ListNode* r2 = mergesort(tt,tail);
		ListNode* head_p = combine(r1,r2);
		return head_p;
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	ListNode* head = new ListNode(3);
	ListNode* head1 = new ListNode(2);
	ListNode* tail = new ListNode(4);
	head->next = head1;
	head1->next = tail;
	Solution s;
	s.sortList(head);
	return 0;
}

