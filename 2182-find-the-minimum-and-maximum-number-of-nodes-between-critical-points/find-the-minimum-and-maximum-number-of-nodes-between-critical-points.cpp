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
        int cnt=1;
        int fir=-1,last=-1;
        int mini=1e9,maxi=0;
        ListNode* prev=head,*ptr=head->next;
        while(ptr->next){
            if((ptr->val>prev->val && ptr->val>ptr->next->val) || (ptr->val<prev->val && ptr->val<ptr->next->val)){
                if(fir==-1) fir=cnt;
                else{
                    if(last!=-1) mini=min(mini,cnt-last);
                    last=cnt;
                    mini=min(mini,last-fir);
                    maxi=max(maxi,last-fir);
                }
            }
            prev=ptr;
            ptr=ptr->next;
            cnt++;
        }
        if(mini==1e9 || maxi==0) return {-1,-1};
        return {mini,maxi};
    }
};