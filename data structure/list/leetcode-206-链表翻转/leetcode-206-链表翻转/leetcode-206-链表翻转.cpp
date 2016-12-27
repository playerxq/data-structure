// leetcode-206-链表翻转.cpp : 定义控制台应用程序的入口点。
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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre, *cur,*nx;
		pre = NULL;
		cur = nx = head;
		if(head==NULL)
			return head;
		nx = head->next;
		while(cur!=NULL)
		{
			cur->next = pre;
			pre = cur;
			cur = nx;
			if(nx!=NULL)
				nx = nx->next;
		}
		return pre;
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

