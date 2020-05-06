/*
public class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}*/
public class Solution {
    public ListNode FindFirstCommonNode(ListNode pHead1, ListNode pHead2) {
         ListNode cur1=pHead1;
         ListNode cur2=pHead2;
        while  (cur1!=cur2){
            cur1=(cur1==null)? pHead2:cur1.next;
            cur2=(cur2==null)? pHead1:cur2.next;
        }
        return cur1;
    }
}
/* java版本提供了一个非常巧妙的解法，无论是长短链表，都让他们走一个长加短的
这样他们俩就一定可以相遇 */