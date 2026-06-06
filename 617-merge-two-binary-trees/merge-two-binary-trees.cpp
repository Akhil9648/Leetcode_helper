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
    void merge(TreeNode* root1,TreeNode* root2){
        if(root1 && root2) root1->val+=root2->val;
        if(root1->left && root2->left) merge(root1->left,root2->left);
        else if(!root1->left) root1->left=root2->left;
        if(root1->right && root2->right) merge(root1->right,root2->right);
        if(!root1->right) root1->right=root2->right;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1) return root2;
        if(!root2) return root1;
        if(!root1 && !root2) return NULL;
        merge(root1,root2);
        return root1;
    }
};