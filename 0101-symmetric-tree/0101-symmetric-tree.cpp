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
    bool check(TreeNode* Node1,TreeNode* Node2)
    {
        if(Node1 == NULL and Node2 == NULL)
        {
            return true;
        }
        if(Node1 == NULL || Node2 == NULL)
        {
            return false;
        }
        if(Node1->val != Node2->val)
        {
            return false;
        }
        return check(Node1->left,Node2->right) and check(Node1->right,Node2->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        TreeNode* node1 = root->left;
        TreeNode* node2 = root->right;
        return check(node1,node2);
    }
};