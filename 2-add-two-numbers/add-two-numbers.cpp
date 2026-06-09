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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* a=l1,*b=l2;
        ListNode* ans=new ListNode(-1);
        ListNode* temp=ans;
        while(a && b){
            int sum=a->val+b->val+carry;
            if(sum>=10){
                carry=sum/10;
            }
            else carry=0;
            sum%=10;
            ListNode* curr=new ListNode(sum);
            temp->next=curr;
            temp=curr;
            a=a->next;
            b=b->next;
        }
        while(a){
            int sum=a->val+carry;
            if(sum>=10){
                carry=sum/10;
            }
            else carry=0;
            sum%=10;
            ListNode* curr=new ListNode(sum);
            temp->next=curr;
            temp=curr;
            a=a->next;
        }
        while(b){
            int sum=b->val+carry;
            if(sum>=10){
                carry=sum/10;
            }
            else carry=0;
            sum%=10;
            ListNode* curr=new ListNode(sum);
            temp->next=curr;
            temp=curr;
            b=b->next;
        }
        if(carry>0){
            ListNode* curr=new ListNode(carry);
            temp->next=curr;
            temp=curr;
        }
        return ans->next;
    }
};