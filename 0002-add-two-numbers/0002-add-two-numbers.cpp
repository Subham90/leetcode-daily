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
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;
        ListNode* dummyhead = new ListNode(-1);
        ListNode* curr = dummyhead;
        int sum;
        while(l1!=NULL || l2!=NULL)
        {
            sum = carry;
            if(l1!=NULL)
            {
                sum+=l1->val;
                l1 = l1->next;
            }
            if(l2!=NULL)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            ListNode* temp = new ListNode(sum%10);
            curr->next = temp;
            curr=curr->next;
            carry = sum/10;
        }
        
        if(carry!=0)
        {
            ListNode* f = new ListNode(carry);
            curr->next = f;
            curr=curr->next;
        }
        
        return dummyhead->next;
    }
};