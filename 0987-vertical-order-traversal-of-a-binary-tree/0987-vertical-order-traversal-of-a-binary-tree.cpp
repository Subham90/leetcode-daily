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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mp;// this will store vertiv
        queue<pair<TreeNode*,pair<int,int>>>q; // This will store node,vertical,level
        q.push({root,{0,0}});
        vector<vector<int>>ans;
        while(!q.empty())
        {
            auto it = q.front();
            TreeNode* node = it.first;
            int x = it.second.first;
            int y = it.second.second;
            q.pop();
            mp[x][y].insert(node->val);
            
            if(node->left)
            {
                q.push({node->left,{x-1,y+1}});
            }
            if(node->right)
            {
                q.push({node->right,{x+1,y+1}});
            }
        }
        
        for(auto it: mp)
        {
            vector<int>v;
            for(auto itt: it.second)
            {
                v.insert(v.end(),itt.second.begin(),itt.second.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
};