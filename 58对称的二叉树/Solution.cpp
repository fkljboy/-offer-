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
    bool isSymmetrical(TreeNode* pRoot)
    {
        if (pRoot==NULL) return true;
        return ismirror(pRoot,pRoot);
    }
private :
    bool ismirror(TreeNode* pRoot1,TreeNode* pRoot2){
    if (pRoot1==NULL&&pRoot2==NULL) return true;
    if (pRoot1==NULL||pRoot2==NULL) return false;
    if (pRoot1->val!=pRoot2->val) return false;
    return ismirror(pRoot1->left,pRoot2->right)&&ismirror(pRoot1->right,pRoot2->left);
}

};
/* 根据二叉树的镜像函数来判断，二叉树的镜像之前做过，只是把原来的两个
二叉树的比较变成了对一个二叉树的两个子树的比较 */