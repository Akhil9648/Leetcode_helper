/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* slow=headA,*fast=headB;
        int f1=0,f2=0;
        while(slow!=fast){
            slow=slow->next;
            if(!slow){
                if(f1) return NULL;
                slow=headB;
                f1=1;
            }
            fast=fast->next;
            if(!fast){
                if(f2) return NULL;
                fast=headA;
                f2=1;
            }

        }
        return slow;
    }
};