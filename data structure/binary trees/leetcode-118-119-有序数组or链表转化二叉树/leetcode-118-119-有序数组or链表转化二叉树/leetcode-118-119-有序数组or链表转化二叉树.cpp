// leetcode-118-119-有序数组or链表转化二叉树.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//array
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBST(nums,0,nums.size()-1);
}
TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end){
    //inclusive start to end;
    if(start > end)return NULL;
    int mid = (start + end)/2;
    TreeNode* node = new TreeNode(nums[mid]);
    node->left = (start == end) ? NULL : sortedArrayToBST(nums,start,mid-1);
    node->right= (start == end) ? NULL : sortedArrayToBST(nums,mid+1,end);
    return node;
}
};
//list
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int cnt = 0;
        ListNode* p = head;
        while(p!=NULL)
        {
            cnt++;
            p = p->next;
        }
        return sortedArrayToBST(head,cnt);
    }
    TreeNode* sortedArrayToBST(ListNode* head, int cnt){
        if(cnt==0||head==NULL)return NULL;
        int mid = (cnt)/2;
        int t = mid;
        ListNode* p = head;
        while(p!=NULL&&mid)
        {
            mid--;
            p = p->next;
        }
        TreeNode* node = new TreeNode(p->val);
        node->left = (cnt==1) ? NULL : sortedArrayToBST(head,t);
        node->right= (cnt==1) ? NULL : sortedArrayToBST(p->next,cnt-t-1);
        return node;
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

