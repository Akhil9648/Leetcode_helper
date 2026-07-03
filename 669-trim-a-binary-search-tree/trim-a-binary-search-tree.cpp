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
    TreeNode* solve(TreeNode* root,int low,int high){
        if(!root) return NULL;
        TreeNode* l=solve(root->left,low,high);
        TreeNode* r=solve(root->right,low,high);
        root->left=l;
        root->right=r;
        if(root->val<low){
            return r;
        }
        if(root->val>high) return l;
        return root;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return solve(root,low,high);
    }
};