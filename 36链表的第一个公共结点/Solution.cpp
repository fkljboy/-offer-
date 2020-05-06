/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1 == NULL || pHead2 == NULL){
            return NULL;
        }
        // 获得两个链表的长度
        unsigned int len1 = GetListLength(pHead1);
        unsigned int len2 = GetListLength(pHead2);
        // 默认 pHead1 长， pHead2短，如果不是，再更改
        ListNode* pHeadLong = pHead1;
        ListNode* pHeadShort = pHead2;
        int LengthDif = len1 - len2;
        // 如果 pHead1 比 pHead2 小
        if(len1 < len2){
            ListNode* pHeadLong = pHead2;
            ListNode* pHeadShort = pHead1;
            int LengthDif = len2 - len1;
        }
        // 将长链表的前面部分去掉，使两个链表等长
        for(int i = 0; i < LengthDif; i++){
            pHeadLong = pHeadLong->next;
        }
        
        while(pHeadLong != NULL && pHeadShort != NULL && pHeadLong != pHeadShort){
            pHeadLong = pHeadLong->next;
            pHeadShort = pHeadShort->next;
        }
        return pHeadLong;
    }
private:
    // 获得链表长度
    unsigned int GetListLength(ListNode* pHead){
        if(pHead == NULL){
            return 0;
        }
        unsigned int length = 1;
        while(pHead->next != NULL){
            pHead = pHead->next;
            length++;
        }
        return length;
    }
};
/* 常规解法，就是先统计出长度，然后求出长度差，然后让长的一个链表先走
一个长度差，然后俩链表一起走，相遇即可 */