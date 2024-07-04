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
        vector<int>v;
        ListNode* temp = head;
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        while(temp!=NULL and temp->next!=NULL)
        {
            v.push_back(temp->val);
            temp = temp->next->next;
        }
        if(temp!=NULL)
        {
            v.push_back(temp->val);
        }
        temp = head->next;
        while(temp!=NULL and temp->next!=NULL)
        {
            v.push_back(temp->val);
            temp = temp->next->next;
        }
        if(temp!=NULL)
        {
            v.push_back(temp->val);
        }
        temp = head;
        int i=0;
        while(temp!=NULL)
        {
            temp->val=v[i];
            i++;
            temp=temp->next;
        }
        return head;
    }
};