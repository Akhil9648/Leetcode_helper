/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;
        map<Node*,Node*>mp;
        queue<Node*>q;
        q.push(node);
        while(!q.empty()){
            Node* curr=q.front();
            q.pop();
            int value=curr->val;
            Node* a;
            if(!mp.count(curr)){
                a=new Node(curr->val);
                mp[curr]=a;
            }
            else a=mp[curr];
            for(auto it:curr->neighbors){
               if(!mp.count(it)){
                    mp[it]=new Node(it->val);
                    q.push(it);
               }
               a->neighbors.push_back(mp[it]); 
            }
            cout<<value<<" ";
        }
        return mp[node];
    }
};