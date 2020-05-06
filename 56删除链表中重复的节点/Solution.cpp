public class Solution{
    public ListNode deleteDuplication(ListNode* pHead)
    {
        if (pHead==NULL||pHead.next==NULL) return pHead;
        ListNode* next=pHead->next;
        if (next->val==pHead->val){
            while(next!=NULL&&next->val==pHead->val)
                next=next->next;
            return deleteDuplication(next);
        }
        else{
            pHead->next=deleteDuplication(pHead->next);
            return pHead;
        }
    }
}
/* 这道题就是递归，如果有重复的值就让next指针继续向后指，如果遇到不相等的
就从不相等的就从不相等的那个开始进入递归 */