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
        ListNode* temp1=l1,*temp2=l2;
        int carry=0;
        ListNode* ans=new ListNode(-1);
        ListNode* ptr=ans;
        while(temp1 && temp2){
            int sum=temp1->val+temp2->val+carry;
            carry=sum/10;
            sum%=10;
            ListNode* curr=new ListNode(sum);
            ptr->next=curr;
            ptr=curr;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1){
            int sum=temp1->val+carry;
            carry=sum/10;
            sum%=10;
            ListNode* curr=new ListNode(sum);
            ptr->next=curr;
            ptr=curr;
            temp1=temp1->next;
        }
        while(temp2){
            int sum=temp2->val+carry;
            carry=sum/10;
            sum%=10;
            ListNode* curr=new ListNode(sum);
            ptr->next=curr;
            ptr=curr;
            temp2=temp2->next;
        }
        if(carry>0){
            ListNode* curr=new ListNode(carry);
            ptr->next=curr;
        }
        return ans->next;
    }
};