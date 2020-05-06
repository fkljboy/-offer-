class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
       vector<int>res;
    vector<int>& printListFromTailToHead(ListNode* head) {
        if(head!=nullptr) {
            if(head->next!=nullptr) {
                printListFromTailToHead(head->next);
            }
            res.push_back(head->val);
        }
        return res;
    }
};
//java 的递归解法