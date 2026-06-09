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
    int len(ListNode* head){
        int cnt=0;
        ListNode* temp=head;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l=len(head);
        l-=n;
        if(l==0) return head->next;
        int cnt=0;
        ListNode* temp=head;
        while(temp){
            cnt++;
            if(cnt==l) temp->next=temp->next->next;
            temp=temp->next;
        }
        return head;
    }
};