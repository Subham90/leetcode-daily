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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        ListNode* newHead = new ListNode(-1);
        ListNode* dummy = newHead;
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i])
            {
                pq.push({lists[i]->val,lists[i]});
            }
        } // n*logk
        
        while(!pq.empty()) // k*3logk
        {
            auto it = pq.top();
            pq.pop();
            dummy->next = it.second;
            dummy = it.second;
            if(it.second->next)
            pq.push({it.second->next->val,it.second->next});
        }
        return newHead->next;
    }
};