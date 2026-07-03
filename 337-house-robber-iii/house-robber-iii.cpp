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
    int solve(TreeNode* root,int flag,map<pair<TreeNode*,int>,int>& mp){
        if(!root) return 0;
        if(mp.count({root,flag})) return mp[{root,flag}];
        int take=0,notTake=0;
        if(!flag){
            take=root->val+solve(root->left,1,mp)+solve(root->right,1,mp);
            notTake=solve(root->left,0,mp)+solve(root->right,0,mp);
        }
        else{
            notTake=solve(root->left,0,mp)+solve(root->right,0,mp);
        }
        return mp[{root,flag}]=max(take,notTake);
    }
    int rob(TreeNode* root) {
        map<pair<TreeNode*,int>,int>mp;
        return solve(root,0,mp);
    }
};