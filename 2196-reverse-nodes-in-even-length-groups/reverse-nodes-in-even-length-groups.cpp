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
    pair<ListNode*,ListNode*> reverse(ListNode* start,ListNode* end){
        ListNode* ptr=start,*nxt=NULL;
        ListNode* rev=NULL;
        while(ptr!=end){
            nxt=ptr->next;
            ptr->next=rev;
            rev=ptr;
            ptr=nxt;
        }
        return {start,rev};
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode dummy(0);
        dummy.next=head;
        ListNode* temp=head,*start=&dummy;
        int n=0,s=1;
        while(temp){
            temp=temp->next;
            n++;
            if(n==s){
                if(n%2==0){
                   pair<ListNode*,ListNode*> a=reverse(start->next,temp);
                    start->next=a.second;
                    a.first->next=temp;
                    start=a.first;
                }
                else{
                    while(n-- && start->next){
                        start = start->next;
                    }
                }
                n=0;
                s++;
                temp=start->next;
            }
        }
        if(n > 0 && n % 2 == 0){
            pair<ListNode*,ListNode*> a=reverse(start->next,temp);
            start->next=a.second;
            a.first->next=temp;
        }
        return dummy.next;
    }
};