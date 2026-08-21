/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* merge(Node* head,Node* nxt){
        if(!head) return head;
        Node* ptr=head,*tail=head;
        while(ptr){
            tail=ptr;
            if(ptr->child){
                Node* nxt=ptr->next;
                ptr->next=ptr->child;
                ptr->child->prev=ptr;
                ptr->child=NULL;
                Node* child_tail=merge(ptr->next,nxt);
                if(child_tail) tail=child_tail;
                ptr=nxt;
            }
            else ptr=ptr->next;
        }
        tail->next=nxt;
        if(nxt) nxt->prev=tail;
        return tail;
    }
    Node* flatten(Node* head) {
         merge(head,NULL);
         return head;
    }
};