/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* solve(ListNode* prev , ListNode* temp , ListNode* fast)
    {
        if(temp==NULL)
        {
            return prev;
        }

        fast=temp->next;
        temp->next=prev;
        
        return solve(temp,fast,fast);

    }
    ListNode* reverseList(ListNode* head) {
        ListNode* temp=head;
        ListNode* prev = NULL;
        ListNode* fast = head;
        return solve(NULL  , head, head);
        
        
    }
};