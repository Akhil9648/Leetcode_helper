/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>mp;
        Node* temp=head;
        Node* ans=new Node(-1);
        Node *curr=ans;
        while(temp){
            Node* a=new Node(temp->val);
            curr->next=a;
            curr=a;
            mp[temp]=a;
            temp=temp->next;
        }
        temp=head;
        while(temp){
            mp[temp]->random=mp[temp->random];
            temp=temp->next;
        }
        return ans->next;
    }
};