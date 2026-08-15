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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ptr=head,*prev=head;
        while(ptr){
            while(ptr->next && ptr->val==ptr->next->val) ptr=ptr->next;
            prev->next=ptr->next;
            prev=prev->next;
            ptr=ptr->next;
        }
        return head;
    }
};