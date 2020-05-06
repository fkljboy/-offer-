public class Solution {
    TreeNode head = null;
    TreeNode realHead = null;
    public TreeNode Convert(TreeNode pRootOfTree) {
        ConvertSub(pRootOfTree);
        return realHead;
    }
     
    private void ConvertSub(TreeNode pRootOfTree) {
        if(pRootOfTree==null) return;
        ConvertSub(pRootOfTree.left);
        if (head == null) {
            head = pRootOfTree;
            realHead = pRootOfTree;
        } else {
            head.right = pRootOfTree;
            pRootOfTree.left = head;
            head = pRootOfTree;
        }
        ConvertSub(pRootOfTree.right);
    }
}
/* 思路和cpp一样只是这里定义了一个realhead变量将头结点保存了下来
这样就不用再从尾部回到头结点的操作了 */
