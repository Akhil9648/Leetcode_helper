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
    pair<TreeNode*,int> solve(TreeNode* root,int depth){
        if(!root) return {NULL,depth};
        auto l = solve(root->left,depth+1);
        auto r = solve(root->right,depth+1);
        if(l.second==r.second) return {root,l.second};
        return l.second>r.second?l:r;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        auto ans=solve(root,0);
        return ans.first;
    }
};