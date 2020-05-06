class Solution {
    private:
    vector<vector<int> > result;
    vector<int> tmp;
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root == NULL){
            return result;
        }
        
        tmp.push_back(root->val);
        if((expectNumber - root->val ) == 0 && root->left == NULL && root->right == NULL){
            result.push_back(tmp);
        }
        
        //遍历左子树
        FindPath(root->left, expectNumber - root->val);
        //遍历右子树
        FindPath(root->right, expectNumber - root->val);
        
        tmp.pop_back();//注意这里的回溯很重要，因为每次的搜索以后都需要清空tmp
        return result;
    }
};
/* 这道题的重点在于对路径的定义，可知路径的定义是从根节点开始到叶子节点，
所以判断时需要注意，同时在进入递归时需要将传入的参数变为减去之前根节点
之后的值 */