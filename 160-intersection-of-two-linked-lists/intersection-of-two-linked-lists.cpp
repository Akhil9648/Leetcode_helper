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
        int f1=0,f2=0;
        ListNode* temp1=headA,*temp2=headB;
        while(1){
            if(temp1==temp2) return temp1;
            temp1=temp1->next;
            temp2=temp2->next;
            if(temp1==NULL){
                if(f1) return temp1;
                temp1=headB;
                f1=1;
            }
            if(temp2==NULL){
                if(f2) return temp2;
                temp2=headA;
                f2=1;
            }
        }
        return NULL;
    }
};