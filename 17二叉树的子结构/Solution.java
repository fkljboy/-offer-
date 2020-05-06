
public class Solution {
    public boolean HasSubtree(TreeNode root1,TreeNode root2) {
        boolean result=false;
        if(root1!=null&&root2!=null){
            if(root1.val==root2.val)
                result=subtree(root1,root2);
        if (!result){
            result=HasSubtree(root1.left,root2);
        } if (!result){
            result=HasSubtree(root1.right,root2);
        }
        }
        return result;
    }
    private boolean subtree(TreeNode root1,TreeNode root2){
        if (root2==null) return true;
        if (root1==null) return false;
        if (root1.val!=root2.val) return false;
        return subtree(root1.left,root2.left)&&subtree(root1.right,root2.right);
       
    }
}
// 思路同cpp解法