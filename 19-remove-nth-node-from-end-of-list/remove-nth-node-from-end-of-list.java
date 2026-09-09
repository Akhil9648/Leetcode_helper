/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int countNodes(ListNode head){
        int cnt=0;
        ListNode ptr=head;
        while(ptr!=null){
            ptr=ptr.next;
            cnt++;
        }
        return cnt;
    }
    public ListNode removeNthFromEnd(ListNode head, int n) {
        int cnt=countNodes(head);
        int rem=cnt-n;
        if (rem == 0) {
            return head.next;
        }
        ListNode ptr=head;
        for (int i = 1; i < rem; i++) {
            ptr = ptr.next;
        }
        if (ptr.next != null) {
            ptr.next = ptr.next.next;
        }
        return head;
    }
}