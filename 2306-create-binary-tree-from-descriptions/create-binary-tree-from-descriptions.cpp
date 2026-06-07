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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>mp;
        unordered_set<TreeNode*>st;
        TreeNode* root;
        for(auto it:descriptions){
            TreeNode* curr;
            if(mp.count(it[0])){
                curr=mp[it[0]];
            }
            else{
                curr=new TreeNode(it[0]);
                mp[it[0]]=curr;
                root=curr;
                st.insert(curr);
            }
            if(mp.count(it[1])){
                if(st.count(mp[it[1]])) st.erase(mp[it[1]]);
                if(it[2]==1){
                    curr->left=mp[it[1]];
                }
                else curr->right=mp[it[1]];
            }
            else{
                TreeNode* child=new TreeNode(it[1]);
                mp[it[1]]=child;
                if(it[2]==1){
                    curr->left=child;
                }
                else curr->right=child;
            }
        }
        return *st.begin();
    }
};