/* 输入一棵二叉树，判断该二叉树是否是平衡二叉树。
平衡二叉树的定义是：所谓的平衡之意，
就是树中任意一个结点下左右两个子树的高度差不超过 1。 */
class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        int depth = 0;
        return IsBalanced(pRoot, &depth);
    }
private:
    int IsBalanced(TreeNode* pRoot, int* depth){
        if(pRoot == NULL){
            *depth = 0;
            return true;
        }
        int left, right;
        if(IsBalanced(pRoot->left, &left) && IsBalanced(pRoot->right, &right)){
            int diff = left - right;
            if(diff <= 1 && diff >= -1){
                *depth = 1 + (left > right ? left : right);
                return true;
            }
        }
        return false;
    }
};
/* 思路是后序遍历，也就是从二叉树的叶子节点开始遍历，那么首先需要做的就是
先通过递归到达叶子节点，然后对左右树的depth进行记录，每一轮都更新一次
左右之间的差值，如果发现有超过2的则返回false */