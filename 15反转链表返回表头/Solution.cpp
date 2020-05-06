class Solution {
public:
    ListNode* ReverseList(ListNode* head) {
           if (head==NULL||head->next==NULL) return head;
        ListNode* newhead=ReverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return newhead;
    }
};
/* 递归解决，首先通过递归到达链表的末尾，然后将末尾的前一个节点的next->next
也就是末尾的next指向末尾的前一个节点，通过反复的递归就可以将链表完全反转
但是注意在整个递归的过程中newhead一直都是链表的末尾 */