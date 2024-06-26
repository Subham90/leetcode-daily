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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
void ReturnDS(ListNode* head,vector<int>&ds)
{
    if(head==NULL)
        return;
    
    ds.push_back(head->val);
    ReturnDS(head->next,ds);
}
private:
TreeNode* BuildTree(int start,int end,vector<int>&ds)
{
    if(start>end)
        return NULL;
    
    int mid = start+(end-start)/2;
    TreeNode* root = new TreeNode(ds[mid]);
    
    root->left = BuildTree(start,mid-1,ds);
    root->right = BuildTree(mid+1,end,ds);
    
    return root;
}
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>ds;
        ReturnDS(head,ds);
        int start = 0;
        int end = ds.size()-1;
        return BuildTree(start,end,ds);
    }
};