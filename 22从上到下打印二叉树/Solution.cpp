class Solution {
private:
    queue<TreeNode*>  point;
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        point.push(root);
        while (!point.empty()){
            int len=point.size();
            while(len>0){
                len--;
                TreeNode* t=point.front();
                point.pop();
                if (t==NULL) continue;
                res.push_back(t->val);
                point.push(t->left);
                 point.push(t->right);
            }
        }
        return res;
    }
};
/* 用一个队列去解决这个问题是极为巧妙的，首先队列可以将所有的子节点按顺序
存入队列中，而且每打印一个队列中元素的时候总会将该元素的子节点按左右顺序
存入队列，这样保证了逐层从左向右的完整遍历 */