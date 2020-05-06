/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if (pHead==NULL){
            return NULL;
        }
        ListNode* meetingnode =MeetingNode(pHead);
        if (meetingnode ==NULL){
            return NULL;
        }
        int nodesloop=1;
        ListNode* pNode1=meetingnode;
        while (pNode1->next !=meetingnode){
            pNode1=pNode1->next;
            nodesloop++;
        }
        pNode1=pHead;
        for (int i=0;i<nodesloop;i++){
            pNode1=pNode1->next;
        }
        ListNode* pNode2=pHead;
        while (pNode1!=pNode2){
            pNode1=pNode1->next;
            pNode2=pNode2->next;
        }
        return pNode1;
    }
private:
    ListNode* MeetingNode(ListNode* pHead){
        ListNode* pslow=pHead->next;
        if (pslow==NULL){
            return NULL;
        }
        ListNode* pfast=pslow->next;
        while(pfast!=NULL&&pslow!=NULL){
            if (pfast==pslow)
            return pfast;
        
        pslow=pslow->next;
        pfast=pfast->next;
        if(pfast!=NULL){
            pfast=pfast->next;
        }
        }
        return NULL;
    }
};
/* 这道题需要分为两步，首先，需要通过快慢指针来计算出是否存在环
然后从快慢指针的相遇点开始走一圈，同时计数，当再次到达相遇点时，
计数值即为环的长度，然后再设立两个指针，第一个指针从头出发，走
环的长度的路程，然后第二个指针出发，则两指针相遇点即为环的入口 */