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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* temp=head;
        unordered_set<int>st;
        for(int i:nums)
        {
            st.insert(i);
        }
        while(temp!=NULL && st.find(temp->val)!=st.end())
        {
            temp=temp->next;
        }
        head=temp;
        ListNode* prev= temp;
        temp=temp->next;
        while( temp!=NULL)
        {
            if(st.find(temp->val)==st.end())
            {
                prev->next=temp;
                prev=temp;
            }
            temp=temp->next;
        }
        prev->next=NULL;
        return head;
        
    }
};