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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1= headA , *temp2=headB;
        unordered_set<ListNode*>st;
        while(temp1)
        {
           st.insert(temp1); 
           temp1=temp1->next;
        }
        while(temp2!=NULL && st.find(temp2)==st.end())
        {
            temp2=temp2->next;

        }
        return temp2;

        
    }
};