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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int level=0;
        unordered_map<int,int>mp;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            TreeNode* a=it.first;
            int lvl=it.second;
            level=max(level,lvl);
            mp[lvl]=a->val;
            if(a->left){
                q.push({a->left,lvl+1});
            }
            if(a->right){
                q.push({a->right,lvl+1});
            }
        }
        vector<int>ans(level+1);
        for(auto it:mp){
            ans[it.first]=it.second;
        }
        return ans;
    }
};