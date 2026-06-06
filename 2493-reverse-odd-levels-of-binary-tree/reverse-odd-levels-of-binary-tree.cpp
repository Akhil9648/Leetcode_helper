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
    void solve(TreeNode* lft,TreeNode* rght,int i){
        if(!lft || !rght) return;
        if(i%2==1){
            swap(lft->val,rght->val);
        }
        solve(lft->left,rght->right,i+1);
        solve(lft->right,rght->left,i+1);
        return;
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        solve(root->left,root->right,1);
        return root;
    }
};