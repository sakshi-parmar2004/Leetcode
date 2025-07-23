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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;
        ListNode *temp1 = l1, *temp2 = l2;
        int carry = 0;
        while (temp1 != NULL && temp2 != NULL) {
            int a = temp1->val;
            int b = temp2->val;
            int ele = a + b + carry;
            int data = ele % 10;
            ListNode* node = new ListNode(data);
            temp->next = node;
            temp = node;
            carry = ele / 10;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while(temp1!=NULL)
        {
            int data=temp1->val+carry;
            int ele=data%10;
            ListNode* node = new ListNode(ele);
             temp->next = node;
            temp = node;
            carry=data/10;
            temp1=temp1->next;

        }
         while(temp2!=NULL)
        {
            int data=temp2->val+carry;
            int ele=data%10;
            ListNode* node = new ListNode(ele);
            temp->next = node;
            temp = node;
            carry=data/10;
            temp2=temp2->next;
        }
        while(carry!=0)
        {
            int data=carry%10;
            ListNode* node=new ListNode(data);
            temp->next=node;
            temp=node;
            carry=carry/10;
        }

        return dummy->next;
    }
};