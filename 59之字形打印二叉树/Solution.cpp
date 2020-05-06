/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector <int> > result;
        if(pRoot==NULL) return result;
        stack<TreeNode*> s[2];
        s[0].push(pRoot);
        while (!s[0].empty()||!s[1].empty()){
            vector<int> v[2];
            while (!s[0].empty()){
                v[0].push_back(s[0].top()->val);
                if(s[0].top()->left!=NULL){
                    s[1].push(s[0].top()->left);
                }
                if(s[0].top()->right!=NULL){
                    s[1].push(s[0].top()->right);
                }
                s[0].pop();
            }
            if (!v[0].empty()){
                result.push_back(v[0]);
            }
            while (!s[1].empty()){
                v[1].push_back(s[1].top()->val);
                 if(s[1].top()->right!=NULL){
                    s[0].push(s[1].top()->right);
                }
                if(s[1].top()->left!=NULL){
                    s[0].push(s[1].top()->left);
                }
                s[1].pop();
            }
            if (!v[1].empty()){
                result.push_back(v[1]);
            }
        }
        return result;
    }
/*     这道题其实算是比较简单的一道题，因为思路是很清晰的，就是用两个
    栈的交替存储不同层的所有节点，然后再一次弹出的思路，因为栈的先进
    后出特性，所以一层和其下一层的输出一定是相反的，也就实现了之字形 */