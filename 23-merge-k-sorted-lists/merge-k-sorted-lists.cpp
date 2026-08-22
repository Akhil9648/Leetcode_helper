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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        for(auto it:lists){
            if(it) pq.push({it->val,it});
        }
        ListNode* ans=new ListNode(-1);
        ListNode* ptr=ans;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            ListNode* a=it.second;
            if(a->next) pq.push({a->next->val,a->next});
            a->next=NULL;
            ptr->next=a;
            ptr=a;
        }
        return ans->next;
    }
};