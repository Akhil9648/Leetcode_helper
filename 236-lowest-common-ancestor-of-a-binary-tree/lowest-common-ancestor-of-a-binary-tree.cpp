/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode* root,TreeNode* p,TreeNode* q){
        if(!root) return NULL;
        TreeNode *l=solve(root->left,p,q);
        TreeNode* r=solve(root->right,p,q);
        if((l==p && r==q) || (l==q && r==p)) return root;
        if(root==p && (l==q || r==q)) return root;
        if(root==q && (l==p || r==p)) return root;
        if(root==p || root==q) return root;
        if(l) return l;
        return r;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p,q);
    }
};