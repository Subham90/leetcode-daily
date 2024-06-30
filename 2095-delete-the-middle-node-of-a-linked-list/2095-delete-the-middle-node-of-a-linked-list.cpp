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
    ListNode* deleteMiddle(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            n++;
            temp=temp->next;
        }
        if(n == 1)
        {
            return NULL;
        }
        int nodetoreach = ceil((n+1)/2.0);
        if(nodetoreach == 1)
        {
            temp = head->next;
            delete(temp);
            return head;
        }
        temp=head;
        int cnt = 0;
        ListNode* prev = NULL;
        while(temp!=NULL)
        {
            ++cnt;
            if(cnt==nodetoreach)
            {
                prev->next = prev->next->next;
                delete(temp);
                break;
            }
            prev=temp;
            temp=temp->next;
        }
        return head;
    }
};