/*
public class TreeNode {
    int val = 0;
    TreeNode left = null;
    TreeNode right = null;

    public TreeNode(int val) {
        this.val = val;

    }

}
*/
public class Solution {
    boolean isSymmetrical(TreeNode pRoot)
    {
         if (pRoot==null) return true;
        return ismirror(pRoot,pRoot);
    }
    private boolean ismirror(TreeNode pRoot1,TreeNode pRoot2){
    if (pRoot1==null&&pRoot2==null) return true;
    if (pRoot1==null||pRoot2==null) return false;
    if (pRoot1.val!=pRoot2.val) return false;
    return ismirror(pRoot1.left,pRoot2.right)&&ismirror(pRoot1.right,pRoot2.left);
}
}
// 和cpp解法一致