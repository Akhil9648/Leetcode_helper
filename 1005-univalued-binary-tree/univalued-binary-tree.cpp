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
    bool solve(TreeNode* root,int a){
        if(!root) return true;
        if(root->val!=a) return false;
        if(!solve(root->left,a)) return false;
        if(!solve(root->right,a)) return false;
        return true;
    }
    bool isUnivalTree(TreeNode* root) {
        if(!root) return true;
        int  a=root->val;
        return solve(root,a);
    }
};