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
    int findBottomLeftValue(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        unordered_map<int,TreeNode*>mp;
        mp[0]=root;
        int high=0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            TreeNode* nd=it.first;
            int lvl=it.second;
            high=max(high,lvl);
            mp[lvl]=nd;
            if(nd->right){
                q.push({nd->right,lvl+1});
            }
            if(nd->left){
                q.push({nd->left,lvl+1});
            }
        }
        return mp[high]->val;
    }
};