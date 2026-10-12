 /* Definition for singly-linked list.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode* oh = nullptr;
        ListNode* ot = nullptr;
        ListNode* th = nullptr;
        ListNode* tt = nullptr;

        ListNode* c = head;
        ListNode* f = nullptr;

        int len = 0;
        ListNode* temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }
        while (len >= k) {
            int tk = k;
            while (tk > 0) {
                f = c->next;
                
                if (!th) {
                    th = c;
                    tt = c;
                    c->next = nullptr;
                } else {
                    c->next = th;
                    th = c;
                }

                c = f;
                tk--;
            }
            if (!oh) {
                oh = th;
                ot = tt;
            } else {
                ot->next = th;
                ot = tt;
            }
            th = nullptr;
            tt = nullptr;
            len -= k;
        }
        if (c) {
            ot->next = c;
        }
        return oh;
    }
};