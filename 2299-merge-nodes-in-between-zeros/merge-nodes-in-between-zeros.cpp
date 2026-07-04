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
        ListNode* prev=head,*temp=head->next;
        int sum=0;
        while(temp){
            if(temp->val==0){
                if(temp->next) prev->next=temp;
                else prev->next=NULL;
                prev->val=sum;
                prev=temp;
                sum=0;
            }
            else sum+=temp->val;
            temp=temp->next;
        }
        return head;
    }
};