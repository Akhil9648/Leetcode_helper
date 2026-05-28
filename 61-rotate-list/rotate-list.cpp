/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* Rotate(ListNode *head){
        ListNode *temp=head;
        while(temp->next->next){
            temp=temp->next;
        }
        ListNode* ptr=temp->next;
        temp->next->next=head;
        temp->next=NULL;
        return ptr;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int size=0;
        ListNode* temp=head;
        while(temp){
            size++;
            temp=temp->next;
        }
        if(size<=1 || k==0) return head;
        k%=size;
        while(k--) head=Rotate(head);
        return head;
    }
};