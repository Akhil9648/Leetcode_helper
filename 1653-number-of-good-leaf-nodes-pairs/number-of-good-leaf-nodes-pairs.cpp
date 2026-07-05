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
        unordered_map<TreeNode*,vector<TreeNode*>>mp;
        unordered_set<TreeNode*>leaf;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            if(node->left){
                mp[node].push_back(node->left);
                mp[node->left].push_back(node);
                q.push(node->left);
            }
            if(node->right){
                mp[node].push_back(node->right);
                mp[node->right].push_back(node);
                q.push(node->right);
            }
            if(!node->left && !node->right){
                leaf.insert(node);
            }
        }
        int cnt=0;
        for(auto it:leaf){
            queue<pair<TreeNode*,int>>q;
            unordered_set<TreeNode*>vis;
            q.push({it,0});
            while(!q.empty()){
                auto i=q.front();
                q.pop();
                TreeNode* node=i.first;
                int dis=i.second;
                if(node!=it && leaf.count(node)){
                    cnt++;
                    continue;
                }
                if(dis>=distance) continue;
                for(auto u:mp[node]){
                    if(vis.count(u)) continue;
                    vis.insert(u);
                    q.push({u,dis+1});
                }
            }
        }
        return cnt/2;
    }
};