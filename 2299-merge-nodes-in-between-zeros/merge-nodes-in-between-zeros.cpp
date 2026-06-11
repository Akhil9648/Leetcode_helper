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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans=new ListNode(0);
        ListNode* curr=ans;
        ListNode* temp=head;
        temp=temp->next;
        int sum=0;
        while(temp){
            sum+=temp->val;
            if(temp->val==0){
                ListNode * a=new ListNode(sum);
                curr->next=a;
                curr=a;
                sum=0;
            }
            temp=temp->next;
        }
        return ans->next;
    }
};