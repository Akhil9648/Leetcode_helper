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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* temp=head;
        int prev=-1;
        vector<int>arr;
        int b=0;
        while(temp->next){
            int a=temp->val;
            if(prev!=-1 && (a>prev && a>temp->next->val || a<prev && a<temp->next->val)) arr.push_back(b);
            prev=a;
            temp=temp->next;
            b++;
        }
        int mini=INT_MAX,maxi=INT_MIN;
        if(arr.size()<2) return {-1,-1};
        int n=arr.size();
        for(int i=1;i<n;i++){
            int a=arr[i]-arr[i-1];
            mini=min(mini,a);
        }
        return {mini,arr[n-1]-arr[0]};
    }
};