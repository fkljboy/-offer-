/*
public class TreeLinkNode {
    int val;
    TreeLinkNode left = null;
    TreeLinkNode right = null;
    TreeLinkNode next = null;

    TreeLinkNode(int val) {
        this.val = val;
    }
}
*/
public class Solution {
    public TreeLinkNode GetNext(TreeLinkNode pNode)
    {
        if(pNode == null){
            return null;
        }
        TreeLinkNode pNext = null;
        // 当前结点有右子树，那么它的下一个结点就是它的右子树中最左子结点
        if(pNode.right != null){
            TreeLinkNode pRight = pNode.right;
            while(pRight.left != null){
                pRight = pRight.left;
            }
            pNext = pRight;
        }
        // 当前结点无右子树，则需要找到一个是它父结点的左子树结点的结点
        else if(pNode.next != null){
            // 当前结点
            TreeLinkNode pCur = pNode;
            // 父节点
            TreeLinkNode pPar = pNode.next;
            while(pPar != null && pCur == pPar.right){
                pCur = pPar;
                pPar = pCur.next;
            }
            pNext = pPar;
        }
        return pNext;
    }
}
// 和cpp同样的思路