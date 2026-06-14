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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int ans=root->val;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            ans=it->val;
            if(it->right){
                q.push(it->right);
            }
            if(it->left){
                // ans=it->left->val;
                q.push(it->left);
            }
        }
        return ans;
    }
};