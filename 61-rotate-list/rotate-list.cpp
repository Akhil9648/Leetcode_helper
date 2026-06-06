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
    int length(ListNode* head){
        int len=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            len++;
        }
        return len;
    }
    ListNode* rotate(ListNode* head){
        ListNode* temp=head,*fst=head,*curr=NULL;
        while(temp->next){
            curr=temp;
            temp=temp->next;
        }
        temp->next=fst;
        curr->next=NULL;
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int len=length(head);
        if(k<1 || len<=1) return head;
        k%=len;
        while(k--){
            head=rotate(head);
        }
        return head;
    }
};