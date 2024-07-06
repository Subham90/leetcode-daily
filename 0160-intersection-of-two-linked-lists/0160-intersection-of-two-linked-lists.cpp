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
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        int cnt1=0,cnt2=0;
        while(temp1!=NULL)
        {
            cnt1++;
            temp1=temp1->next;
        }
        while(temp2!=NULL)
        {
            cnt2++;
            temp2 = temp2->next;
        }
        temp1 = headA;
        temp2 = headB;
        if(cnt1 > cnt2)
        {
            int diff = cnt1 - cnt2;
            while(diff--)
            {
                temp1 = temp1->next;
            }
        }
        else if(cnt2 > cnt1)
        {
            int diff = cnt2 - cnt1;
            while(diff--)
            {
                temp2 = temp2->next;
            }
        }
        
        while(temp1!=NULL and temp2!=NULL)
        {
            if(temp1==temp2)
            {
                return temp1;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return NULL;
    }
};