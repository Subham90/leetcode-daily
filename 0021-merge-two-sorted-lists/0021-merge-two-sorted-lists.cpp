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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newHead = new ListNode(-1);
        ListNode* dummy = newHead;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        while(temp1!=NULL and temp2!=NULL)
        {
            if(temp1->val < temp2->val)
            {
                dummy->next = temp1;
                dummy = dummy->next;
                temp1 = temp1->next;
            }
            else
            {
                dummy->next = temp2;
                dummy = dummy->next;
                temp2 = temp2->next;
            }
        }
        if(temp1)
        {
            dummy->next = temp1;
        }
        else if(temp2)
        {
            dummy->next = temp2;
        }
        return newHead->next;
    }
};