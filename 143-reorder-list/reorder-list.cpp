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
    int sz(ListNode* head){
        int cnt=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            cnt++;
        }
        return cnt;
    }
    void reorderList(ListNode* head) {
        stack<ListNode*>st;
        int size=sz(head);
        ListNode* temp=head;
        while(temp){
            st.push(temp);
            temp=temp->next;
        }
        temp=head;
        int a=0;
        while(a<size/2){
            ListNode* nxt=temp->next;
            ListNode* tp=st.top();
            st.pop();
            temp->next=tp;
            tp->next=nxt;
            temp=nxt;
            a++;
        }
        temp->next=NULL;
    }
};