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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL)
        {
            return {-1,-1};
        }
        vector<int>v1; // This will store local maxima
        // vector<int>v2; // This will store local minima
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nextl = head->next;
        int i=1;
        while(nextl!=NULL)
        {
            if(prev!=NULL and nextl!=NULL)
            {
                if(curr->val > prev->val and curr->val > nextl->val
                || curr->val < prev->val and curr->val < nextl->val)
                {
                    v1.push_back(i);
                }
            }
            i++;
            prev = curr;
            curr = nextl;
            nextl = nextl->next; 
        }
        if(v1.size()<=1)
        {
            return {-1,-1};
        }
        sort(v1.begin(),v1.end());
        int n = v1.size();
        int mx = abs(v1[n-1]-v1[0]);
        int mn = mx;
        for(int i=0;i<n-1;i++)
        {
            mn = min(mn,abs(v1[i+1]-v1[i]));
        }
        
        return {mn,mx};
    }
};