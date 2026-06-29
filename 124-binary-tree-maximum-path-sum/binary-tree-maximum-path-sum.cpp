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
    int solve(TreeNode* root,int &maxi){
        if(!root) return 0;
        int l=solve(root->left,maxi);
        if(l<0) l=0;
        int r=solve(root->right,maxi);
        if(r<0) r=0;
        int sum=l+r+root->val;
        maxi=max(maxi,sum);
        return max(l,r)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxi=-1e9;
        solve(root,maxi);
        return maxi;
    }
};