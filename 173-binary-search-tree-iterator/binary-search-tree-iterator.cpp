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
class BSTIterator {
public:
    vector<int>trav;
    void solve(TreeNode* root){
        if(!root) return;
        if(root->left){
            solve(root->left);
        }
        trav.push_back(root->val);
        if(root->right){
            solve(root->right);
        }
        return;
    }
    int i=0;
    BSTIterator(TreeNode* root) {
        solve(root);
    }
    
    int next() {
        return trav[i++];
    }
    
    bool hasNext() {
        return i<trav.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */