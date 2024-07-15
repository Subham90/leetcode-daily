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
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>st1,st2;
        if(root==NULL)
        {
            return ans;
        }
        st1.push(root);
        while(!st1.empty())
        {
            TreeNode* newroot = st1.top();
            ans.push_back(newroot->val);
            st1.pop();
            if(newroot->left!=NULL)
            {
                st1.push(newroot->left);
            }
            if(newroot->right!=NULL)
            {
                st1.push(newroot->right);
            }
        }
        reverse(ans.begin(),ans.end());
        // while(!st2.empty())
        // {
        //     ans.push_back(st2.top()->val);
        //     st2.pop();
        // }
        return ans;
    }
};