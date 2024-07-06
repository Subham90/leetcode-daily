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
ListNode* reversell(ListNode* head)
{
//     ListNode* temp = head;
//     if(temp == NULL || temp->next == NULL)
//     {
//         return temp;
//     }
//     ListNode* prev = NULL;
//     while(temp!=NULL)
//     {
//         ListNode* front = head->next;
//         head->next = prev;
//         prev = temp;
//         temp = temp->next;
//     }
    
//     return prev;
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    
    ListNode* newHead = reversell(head->next);
    head->next->next = head;
    head->next = NULL;
    
    return newHead;
    
}
public:
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next!=NULL and fast->next->next!=NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* newHead = reversell(slow->next);
        slow = head;
        while(newHead!=NULL)
        {
            if(newHead->val!=slow->val)
            {
                return false;
            }
            newHead = newHead->next;
            slow = slow->next;
        }
        return true;
    }
};