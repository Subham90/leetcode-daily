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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL)
        {
            return {};
        }
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        bool dir = true;
        while(!q.empty())
        {
            int size = q.size();
            vector<int>ds(size);
            for(int i=0;i<size;++i)
            {
                TreeNode* node = q.front();
                q.pop();
                int index=dir? i : size-i-1;
                ds[index] = node->val;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            ans.push_back(ds);
            dir = !dir;
        }
        return ans;
    }
};