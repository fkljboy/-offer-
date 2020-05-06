
public class Solution {
    public void Mirror(TreeNode root) {
        if (root==null) return ;
        swap(root);
        Mirror(root.left);
        Mirror(root.right);
    }
    private void swap(TreeNode root){
        TreeNode t=root.right;
        root.right=root.left;
        root.left=t;
    }
}