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
private:
    ListNode* findmiddle(ListNode* head)
    {
        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast!=NULL and fast->next!=NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
private:
    ListNode* merge(ListNode* lefthead,ListNode* righthead)
    {
        ListNode* newHead = new ListNode(-1);
        ListNode* dummy = newHead;
        
        while(lefthead!=NULL and righthead!=NULL)
        {
            if(lefthead->val < righthead->val)
            {
                dummy->next = lefthead;
                dummy = lefthead;
                lefthead = lefthead->next;
            }
            else
            {
                dummy->next = righthead;
                dummy = righthead;
                righthead = righthead->next;
            }
        }
        if(lefthead!=NULL)
        {
            dummy->next = lefthead;
        }
        else if(righthead!=NULL)
        {
            dummy->next = righthead;
        }
        return newHead->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
           return head;   
        }
        ListNode* middle = findmiddle(head);
        ListNode* righthead = middle->next;
        ListNode* lefthead = head;
        middle->next = NULL;
        
        lefthead = sortList(lefthead);
        righthead = sortList(righthead);
        
        return merge(lefthead,righthead);
    }
};