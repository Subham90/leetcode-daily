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
    ListNode* mergeNodes(ListNode* head) {
        vector<int>v;
        ListNode* temp = head;
        temp = temp->next;
        int sum = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* newhead = dummy;
        while(temp!=NULL)
        {
            if(temp->val == 0)
            {
                v.push_back(sum);
                sum = 0;
            }
            else
            {
                sum+= temp->val;
            }
            temp = temp->next;
        }
        for(auto it: v)
        {
            ListNode* temp = new ListNode(it);
            dummy->next = temp;
            dummy = dummy->next;
        }
        return newhead->next;
    }
};