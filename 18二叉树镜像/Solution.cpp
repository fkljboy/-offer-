class Solution {
public:
    void Mirror(TreeNode *pRoot) {
            if(pRoot==NULL) return ;
        swap(pRoot);
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
private:
    void swap(TreeNode* proot){
        TreeNode* t=proot->right;
        proot->right=proot->left;
        proot->left=t;
    }
};
// 先交换根节点，在进入递归对根节点的子节点进行交换，思路明确