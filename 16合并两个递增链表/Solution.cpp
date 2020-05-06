class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        
        if(pHead1 == NULL){
            return pHead2;
        }
        else if(pHead2 == NULL){
            return pHead1;
        }
        ListNode* pMergedHead = NULL;
        if(pHead1->val < pHead2->val){
            pMergedHead = pHead1;
               pMergedHead->next = Merge(pHead1->next, pHead2);
        }
        else{
            pMergedHead = pHead2;
               pMergedHead->next = Merge(pHead1, pHead2->next);
        }
        return pMergedHead;
        }
    }
/* 先判断输入的链表是否为空的指针。如果第一个链表为空，则直接返回第二个链表；
如果第二个链表为空，则直接返回第一个链表。如果两个链表都是空链表，
判断当前指针，哪个链表中的值小，即赋给合并链表指针即可。使用递归就可以轻松实现。
 */