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
            vector<vector<int> > result;
            if(pRoot == NULL){
                return result;
            }
            queue<TreeNode* > nodes[2];
            nodes[0].push(pRoot);
            while(!nodes[0].empty() || !nodes[1].empty()){
                vector<int> v[2];
                while(!nodes[0].empty()){
                    v[0].push_back(nodes[0].front()->val);
                    if(nodes[0].front()->left != NULL){
                        nodes[1].push(nodes[0].front()->left);
                    }
                    if(nodes[0].front()->right != NULL){
                        nodes[1].push(nodes[0].front()->right);
                    }
                    nodes[0].pop();
                }
                if(!v[0].empty()){
                    result.push_back(v[0]);
                }
                while(!nodes[1].empty()){
                    v[1].push_back(nodes[1].front()->val);
                    if(nodes[1].front()->left != NULL){
                        nodes[0].push(nodes[1].front()->left);
                    }
                    if(nodes[1].front()->right != NULL){
                        nodes[0].push(nodes[1].front()->right);
                    }
                    nodes[1].pop();
                }
                if(!v[1].empty()){
                    result.push_back(v[1]);
                }
            }
            return result;
        }
    
};
/* 这道题和上一道题一模一样的解法反而更加简单，不考虑之字形，只要用
队列就可以完成任务 */