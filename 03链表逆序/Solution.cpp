// 输入一个链表，按链表从尾到头的顺序返回一个ArrayList。

class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int>res;
        stack<ListNode*>node;
        ListNode* pNode=head;
        while(pNode!=nullptr) {
            node.push(pNode);
            pNode=pNode->next;
        }
        while(!node.empty()) {
            pNode=node.top();
            node.pop();
            res.push_back(pNode->val);
        }
        return res;
    }
};
/* cpp的栈空间解法 注意cpp的空指针定义和栈定义和java的区别
有一点区别需要注意 cpp的pop是没有返回值的，所以需要使用 
top方法将栈顶元素提取出来
*/
