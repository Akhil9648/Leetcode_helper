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
    ListNode* reverse(ListNode* head){
        ListNode* ptr=head,*prev=NULL;
        while(ptr){
            ListNode* nxt=ptr->next;
            ptr->next=prev;
            prev=ptr;
            ptr=nxt;
        }
        return prev;
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* temp=head,*start=head,*prev=NULL;
        int s=1,n=0;
        while(temp){
            n++;
            if(n==s){
                cout<<n<<" "<<s<<endl;
                if(n%2==0){
                    ListNode* nxt=temp->next;
                    temp->next=NULL;
                    temp=reverse(start);
                    prev->next=temp;
                    start->next=nxt;
                    temp=start;
                    prev=temp;
                    start=nxt;
                }
                else{
                    prev=temp;
                    start=temp->next;
                }
                cout<<"val"<<"  "<<temp->val<<endl;
                n=0;
                s++;
            }
            temp=temp->next;
        }
        if(n%2==0){
            temp=reverse(start);
            prev->next=temp;
        }
        return head;
    }
};