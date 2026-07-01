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
    ListNode* reverse(ListNode* head){
        ListNode* temp=head,*prev=NULL;
        while(temp){
            ListNode* nxt=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nxt;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int a=k;
        ListNode* temp=head,*start=head,*prev;
        while(temp){
            a--;
            if(a==0){
                ListNode* nxt=temp->next;
                temp->next=NULL;
                ListNode *b=reverse(start);
                if(start==head) head=temp;
                else prev->next=temp;
                start->next=nxt;
                temp=start;
                prev=start;
                start=nxt;
                a=k;
            }
            temp=temp->next;
        }   
        return head;
    }
};