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
        Node* ans=new Node(-1);
        Node* ptr=ans,*temp=head;
        unordered_map<Node*,Node*>mp;
        while(temp){
            Node* curr=new Node(temp->val);
            ptr->next=curr;
            ptr=curr;
            mp[temp]=curr;
            temp=temp->next;
        }
        ptr=ans->next;
        temp=head;
        while(temp){
            Node* a=temp->random;
            if(a==NULL) ptr->random=NULL;
            else{
                ptr->random=mp[a];
            }
            temp=temp->next;
            ptr=ptr->next;
        }
        return ans->next;
    }
};