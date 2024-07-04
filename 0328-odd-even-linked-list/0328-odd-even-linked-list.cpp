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
    ListNode* oddEvenList(ListNode* head) {
       if(head == NULL || head->next == NULL)
       {
           return head;
       }
        ListNode* evenHead = head->next;
        ListNode* tempodd = head;
        ListNode* tempeven = head->next;
        while(tempeven!=NULL and tempeven->next!=NULL)
        {
            tempodd->next = tempodd->next->next;
            tempodd = tempodd->next;
            tempeven->next = tempeven->next->next;
            tempeven = tempeven->next;
        }
        tempodd->next = evenHead;
        return head;
    }
};