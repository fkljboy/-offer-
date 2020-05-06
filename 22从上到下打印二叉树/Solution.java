
public class Solution {
    private Queue<TreeNode> point=new LinkedList<TreeNode>();
    public ArrayList<Integer> PrintFromTopToBottom(TreeNode root) {
         ArrayList<Integer> res=new ArrayList<>();
        point.offer(root);
        while (!point.isEmpty()){
            int len=point.size();
            while(len>0){
                len--;
                TreeNode t=point.peek();
                point.poll();
                if (t==null) continue;
                res.add(t.val);
                point.offer(t.left);
                 point.offer(t.right);
            }
        }
        return res;
}
需要注意Queue和linkedlist 的关系和初始化问题，还有queue的offer 
poll  peek方法