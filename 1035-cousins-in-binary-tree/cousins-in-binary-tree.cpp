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
    unordered_map<int,int>par;
    int a,b,fl;
    void solve(TreeNode* root,TreeNode* pare,int x,int y,int dep){
        if(!root) return ;
        if(root->val==x){
            a=dep;
            par[x]=pare?pare->val:-1;
            fl+=0.5;
        }
        if(root->val==y){
            b=dep;
            par[y]=pare?pare->val:-1;
            fl+=0.5;
        }
        if(fl==1) return;
        solve(root->left,root,x,y,dep+1);
        solve(root->right,root,x,y,dep+1);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        solve(root,NULL,x,y,0);
        if(par[x]==par[y]) return false;
        return a==b;
    }
};