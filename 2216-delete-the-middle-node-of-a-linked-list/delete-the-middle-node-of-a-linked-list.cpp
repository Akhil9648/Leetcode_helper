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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow=head,*fast=head,*ptr=NULL;
        if(!head || !head->next) return NULL;
        while(fast && fast->next){
            ptr=slow;
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) break;
        }
        ptr->next=ptr->next->next;
        return head;
    }
};