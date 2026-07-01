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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        int index=1;
        ListNode* temp=head->next,*ptr=head,*prev=head->next;
        while(temp){
            index++;
            if(index%2==1){
                ListNode* nxt=ptr->next;
                ListNode *tmnxt=temp->next;
                ptr->next=temp;
                ptr=temp;
                temp->next=nxt;
                prev->next=tmnxt;
                temp=prev;
                prev=tmnxt;
            }
            temp=temp->next;
        }
        return head;
    }
};