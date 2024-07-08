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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k==0)
        {
            return head;
        }
        ListNode* temp = head;
        ListNode* tail = NULL;
        int len = 0;
        while(temp!=NULL)
        {
            tail = temp;
            len++;
            temp = temp->next;
        }
        tail->next = head;
        int nodetoreach;
        if(k >= len)
        {
             nodetoreach = len - (k%len);
        }
        else  nodetoreach = len - k;
        int cnt = 0;
        temp = head;
        while(temp!=NULL)
        {
            cnt++;
            if(cnt==nodetoreach)
            {
                head = temp->next;
                temp->next = NULL;
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};