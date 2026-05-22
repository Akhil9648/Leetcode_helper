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
    int countPairs(TreeNode* root, int distance) {
        if(!root) return 0;
        unordered_map<TreeNode*, vector<TreeNode*>>st;
        unordered_set<TreeNode*>leaf;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            if(it->left){
                st[it].push_back(it->left);
                st[it->left].push_back(it);
                q.push(it->left);
            }
            if(it->right){
                st[it].push_back(it->right);
                st[it->right].push_back(it);
                q.push(it->right);
            }
            if(!it->left && !it->right){
                leaf.insert(it);
            }
        }
        int cnt=0;
        for(auto it:leaf){
            queue<pair<TreeNode*,int>>ch;
            unordered_set<TreeNode*> vis;
            ch.push({it,0});
            vis.insert(it);
            while(!ch.empty()){
                auto iu=ch.front();
                ch.pop();
                if(iu.second==distance) continue;
                for(auto i:st[iu.first]){
                    if(!vis.count(i)){
                        vis.insert(i);
                        ch.push({i,iu.second+1});
                        if(leaf.count(i) && i!=it) cnt++;
                    }
                }
            }
        }
        return cnt/2;
    }
};