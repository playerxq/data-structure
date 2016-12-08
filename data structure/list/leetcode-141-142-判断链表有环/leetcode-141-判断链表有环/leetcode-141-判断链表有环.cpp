// leetcode-141-�ж������л�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head||head->next==NULL)
            return 0;
        ListNode* slow, *fast;
        slow = head;
        fast = head;
        while(fast->next&&fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
                return 1;
        }
        return 0;
    }
};
//�õ��������
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head||head->next==NULL)
            return NULL;
        ListNode* slow, *fast;
        slow = head;
        fast = head;
        while(fast->next&&fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
			{
				slow = head;
				while(slow!=fast)
				{
					fast = fast->next;
					slow = slow->next;
				}
				return slow;
			}
        }
        return NULL;
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

