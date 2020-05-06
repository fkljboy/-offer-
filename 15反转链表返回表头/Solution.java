public class Solution {
    public ListNode ReverseList(ListNode head) {
         ListNode newList = new ListNode(-1);
    while (head != null) {
        ListNode next = head.next;
        head.next = newList.next;
        newList.next = head;
        head = next;
    }
    return newList.next;
    }
}
/*每次将q节点插入首个节点p的前面。为了进行下次操作，我们还需要在插入前记录下q后面节点t。

当q为空时，该方法结束，此时完成了整个链表的反转。最后，记得将头结点head指向反转后的首个节点p，

同时将反转后的尾节点的next指针设为空。*/