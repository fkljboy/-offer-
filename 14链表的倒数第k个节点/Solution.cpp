class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
         if(pListHead==NULL) return NULL;
         ListNode* p1=pListHead;
         while (p1!=NULL&&k >0){
             p1=p1->next;
             k--;
         }
        if (k>0) return NULL;
        ListNode* p2=pListHead;
        while(p1!=NULL){
            p2=p2->next;
            p1=p1->next;
        }
        return p2;
    }
};
/* 双指针法，首先使第一个指针前进到正数第k的位置，然后第二个指针开始和
第一个指针一起前进，当第一个指针走到链表的末尾时，第二个指针恰好走到
倒数第k的位置 */