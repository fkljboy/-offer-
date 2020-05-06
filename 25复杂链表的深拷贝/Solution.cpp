class Solution {
public:
    //第一步，复制复杂指针的label和next
    void CloneNodes(RandomListNode* pHead){
        RandomListNode* pNode = pHead;
        while(pNode != NULL){
            RandomListNode* pCloned = new RandomListNode(0);
            pCloned->label = pNode->label;
            pCloned->next = pNode->next;
            pCloned->random = NULL;
            
            pNode->next = pCloned;
            pNode = pCloned->next;
        }
    }
    
    //第二步，处理复杂指针的random
    void ConnectSiblingNodes(RandomListNode* pHead){
        RandomListNode* pNode = pHead;
        while(pNode != NULL){
            RandomListNode* pCloned = pNode->next;
            if(pNode->random != NULL){
                pCloned->random = pNode->random->next;
            }
            pNode = pCloned->next;
        }
    }
    
    //第三步，拆分复杂指针
    RandomListNode* ReconnectNodes(RandomListNode* pHead){
        RandomListNode* pNode = pHead;
        RandomListNode* pClonedHead = NULL;
        RandomListNode* pClonedNode = NULL;
        
        if(pNode != NULL){
            pClonedHead = pClonedNode = pNode->next;
            pNode->next = pClonedNode->next;
            pNode = pNode->next;
        }
        
        while(pNode != NULL){
            pClonedNode->next = pNode->next;
            pClonedNode = pClonedNode->next;
            pNode->next = pClonedNode->next;
            pNode = pNode->next;
        }
        return pClonedHead;
    }
    
    RandomListNode* Clone(RandomListNode* pHead)
    {
        CloneNodes(pHead);
        ConnectSiblingNodes(pHead);
        return ReconnectNodes(pHead);
    }
};
/* 转载了大神Jack cui 的解法https://cuijiahua.com/blog/2017/12/basis_25.html
这里直接复制他的思路：
我们这里将复杂链表的复制过程分解为三个步骤。在写代码的时候我们每一步定义一个函数，这样每个函数完成一个功能，整个过程的逻辑也就非常清晰明了了。

我们这里采用三步：

第一步：复制复杂指针的label和next。但是这次我们把复制的结点跟在元结点后面，而不是直接创建新的链表；
第二步：设置复制出来的结点的random。因为新旧结点是前后对应关系，所以也是一步就能找到random；
第三步：拆分链表。奇数是原链表，偶数是复制的链表。 */