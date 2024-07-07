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
    bool check(ListNode* head,int k)
    {
        ListNode* temp = head;
        int cnt = 0;
        while(temp!=NULL)
        {
            cnt++;
            temp = temp->next;
        }
        if(cnt>=k)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        // Base call
        if(head==NULL)
        {
            return head;
        }
        
        // Reverse first k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        int cnt = 0;
        
        while(curr!=NULL and cnt<k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }
        if(next!=NULL and check(next,k))
        {
            head->next = reverseKGroup(next,k);
        }
        else
        {
            head->next = next;
        }
        return prev;
    }
};