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
    ListNode* solve(ListNode *temp1, ListNode *temp2,int count)
    {
        while(count>0)
        {
            temp2=temp2->next;
            count--;

        }

        while(temp1!=NULL && temp2!=NULL && temp1!=temp2)
        {
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return temp1;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1= headA , *temp2=headB;
       int ct1=0,ct2=0;
        while(temp1)
        {
           ct1++; 
           temp1=temp1->next;
        }
        while(temp2)
        {
          ct2++; 
           temp2=temp2->next;
        }
        if(ct1<ct2)
        {
           return solve(headA,headB,ct2-ct1);
        }
        return solve(headB,headA, ct1-ct2);

        
    }
};