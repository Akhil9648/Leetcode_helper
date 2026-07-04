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
    int size(ListNode* head){
        ListNode* temp=head;
        int cnt=0;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    int pairSum(ListNode* head) {
        stack<int>st;
        int listsize=size(head);
        int cnt=0,maxi=0;
        ListNode* temp=head;
        while(temp){
            st.push(temp->val);
            temp=temp->next;
        }
        temp=head;
        while(cnt<listsize/2){
            int sum=temp->val+st.top();
            maxi=max(maxi,sum);
            st.pop();
            temp=temp->next;
            cnt++;
        }
        return maxi;
    }
};