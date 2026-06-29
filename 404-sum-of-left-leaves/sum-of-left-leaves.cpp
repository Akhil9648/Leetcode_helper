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
    bool isLeaf(TreeNode* root){
        if(!root->left && !root->right) return true;
        return false;
    }
    int solve(TreeNode *root){
        if(!root) return 0;
        int sum=0;
        if(root->left && isLeaf(root->left)){
            sum+=root->left->val;
            cout<<sum<<" ";
            cout<<endl;
        }
        int left=solve(root->left);
        int right=solve(root->right);
        return sum+left+right;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return solve(root);
    }
};