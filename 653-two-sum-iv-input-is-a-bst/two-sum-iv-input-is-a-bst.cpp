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
    bool solve(TreeNode* root,int k,unordered_set<int>&st){
        if(!root) return false;
        if(st.count(k-root->val)) return true;
        st.insert(root->val);
        bool l=solve(root->left,k,st);
        bool r=solve(root->right,k,st);
        if(l || r) return true;
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
       unordered_set<int>st;
       return solve(root,k,st); 
    }
};