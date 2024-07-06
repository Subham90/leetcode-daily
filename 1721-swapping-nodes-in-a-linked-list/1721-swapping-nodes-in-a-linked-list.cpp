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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int>v;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            v.push_back(temp->val);
            temp = temp->next;
        }
        
        int n = v.size();
        int index = n-k+1;
        swap(v[k-1],v[index-1]);
        ListNode* newHead = new ListNode(-1);
        ListNode* dummy = newHead;
        for(auto it: v)
        {
            ListNode* t = new ListNode(it);
            dummy->next = t;
            dummy = dummy->next;
        }
        return newHead->next;
    }
};