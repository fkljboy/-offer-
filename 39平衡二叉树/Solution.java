public class Solution {
    private boolean ib=true;
    public boolean IsBalanced_Solution(TreeNode root) {
        depth(root);
        return ib;
    }
    private int depth(TreeNode root){
        if (root ==null||ib==false)
            return 0;
        int left=depth(root.left);
        int right=depth (root.right);
        if (Math.abs(left-right)<=1){
            return Math.max(left,right)+1;
        }
        else {
            ib=false;
             return Math.max(left,right)+1;
        }
    }
}
/* 思路是和cpp方法一样的，但是实现不一样，这里是定义了一个全局变量ib
然后也是后续遍历，但是返回值定位了depth，这样就可以再计算depth的
同时更新ib，更新ib的计算方法和cpp是一样的 */