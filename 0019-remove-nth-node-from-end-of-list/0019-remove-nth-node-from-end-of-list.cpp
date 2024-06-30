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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int cnt = 0;
        while(temp!=NULL)
        {
            cnt++;
            temp=temp->next;
        }
        if(n > cnt)
        {
            return NULL;
        }
        int nodetoreach = cnt - n + 1;
        temp = head;
        if(temp == NULL)
        {
            return head;
        }
       if (nodetoreach == 1) {
        temp = head;
        head = head->next; // Update head to the next node
        delete temp;
        return head;
        }
        
        int k = 0;
        temp = head;
        ListNode* prev = NULL;
        while(temp!=NULL)
        {
            k++;
            if(k==nodetoreach)
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