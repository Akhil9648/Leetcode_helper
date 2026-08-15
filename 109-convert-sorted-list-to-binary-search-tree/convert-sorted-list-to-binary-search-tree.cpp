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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(ListNode* head){
        if(!head) return NULL;
        if(!head->next) return new TreeNode(head->val); 
        ListNode* slow=head,*fast=head,*pr=head;
        while(fast && fast->next){
            pr=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        pr->next=NULL;
        ListNode* nxt=slow->next;
        slow->next=NULL;
        TreeNode* root=new TreeNode(slow->val);
        root->left=solve(head);
        root->right=solve(nxt);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return solve(head);
    }
};