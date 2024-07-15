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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        vector<int>ans;
        if(root == NULL)
        {
            return ans;
        }
        
        st.push(root);
        while(!st.empty())
        {
            TreeNode* newRoot = st.top();
            ans.push_back(newRoot->val);
            st.pop();
            
            if(newRoot->right != NULL)
            {
                st.push(newRoot->right);
            }
            if(newRoot->left != NULL)
            {
                st.push(newRoot->left);
            }
        }
        return ans;
    }
};