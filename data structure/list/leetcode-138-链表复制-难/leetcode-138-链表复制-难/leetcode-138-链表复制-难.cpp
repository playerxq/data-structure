// leetcode-138-链表复制-难.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <map>
using namespace std;
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)
			return NULL;
		RandomListNode* cur = head;
		RandomListNode* res = NULL;
		RandomListNode* tmp;
		map<RandomListNode*,RandomListNode*> mm;
		while(cur!=NULL)
		{
			RandomListNode* newnode = new RandomListNode(cur->label);
			if(!res)
			{
				res = newnode;
				tmp = newnode;
				mm.insert(make_pair(cur,res));
			}
			else
			{
				res->next = newnode;
				res = res->next;
				mm.insert(make_pair(cur,res));
			}
			cur = cur->next;
		}
		cur = head;
		res = tmp;
		while(cur!=NULL)
		{
			res->random = mm[cur->random];
			cur = cur->next;
			res = res->next;
		}
		return tmp;
    }
};
//不用map直接复制
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)
			return NULL;
		RandomListNode* cur = head;
		RandomListNode* res = NULL;
		RandomListNode* tmp = NULL;
		while(cur!=NULL)
		{
			res = new RandomListNode(cur->label);
			res->next = cur->next;
			cur->next = res;
			cur = res->next;
		}
		cur = head;
		while(cur!=NULL)
		{
			res = cur->next;
			if(cur->random)
				res->random = cur->random->next;
			cur = res->next;
		}
		cur = head;
		tmp = head->next;
		while(cur!=NULL)
		{
			res = cur->next;
			cur->next = res->next;
			cur = cur->next;
			if(cur)
				res->next = cur->next;
		}
		return tmp;
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

