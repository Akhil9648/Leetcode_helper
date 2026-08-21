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
        ListNode* p1=headA,*p2=headB;
        int a=0,b=0;
        while(1){
            if(p1==p2) return p1;
            p1=p1->next;
            p2=p2->next;
            if(!p1){
                if(a) return p2;
                p1=headB;
                a=1;
            }
            if(!p2){
                if(b) return p2;
                p2=headA;
                b=1;
            }
        }
        return NULL;
    }
};